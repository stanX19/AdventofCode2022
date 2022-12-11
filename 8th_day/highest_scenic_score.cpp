#include <iostream>
#include <fstream>
#include <vector>
#include <string>


void map_print(std::vector<std::vector<int>> &map) {
	for (std::vector<int> &row : map){
		for (int &val : row) {
			std::cout << val;
		}
		std::cout << '\n';
	}
}

// need to add safeguard, map can be empty, ret will...
std::vector<std::vector<int>> process_map(std::vector<std::vector<int>> &map)
{
    std::vector<std::vector<int>> ret(map.size(), std::vector<int>(map[0].size(), 0));
	int tallest;
	// scan up down
	for (int x = 0; x < map[0].size(); x++) {
		tallest = -1;
		for (int y = 0; y < map.size(); y++) { // up to bottom
			if (map[y][x] > tallest) {
				tallest = map[y][x];
				ret[y][x]++; //seen
			}
		}
		tallest = -1;
		for (int y = map.size() - 1; y >= 0; y--) { // bottom to up
			if (map[y][x] > tallest) {
				tallest = map[y][x];
				ret[y][x]++; //seen
			}
		}
	}
	// scans left right
	for (int y = 0; y < map.size(); y++) {
		tallest = -1;
		for (int x = 0; x < map[y].size(); x++) { // left to right
			if (map[y][x] > tallest) {
				tallest = map[y][x];
				ret[y][x]++; //seen
			}
		}
		tallest = -1;
		for (int x = map[y].size() - 1; x >= 0; x--) { // right to left
			if (map[y][x] > tallest) {
				tallest = map[y][x];
				ret[y][x]++; //seen
			}
		}
	}
	return ret;
}

std::vector<std::vector<int>> generate_map(std::ifstream &inFile)
{
	std::string						line;
	std::vector<std::vector<int>>	map;
	std::vector<int>				row;
	
	while (std::getline(inFile, line))
	{
		std::cout << line << "\n";
		row.clear();
		for (char &c : line) {
			row.push_back(c - '0');
		}
		map.push_back(row);
	}
	return map;
}

int scenic_score(std::vector<std::vector<int>> &map, int y_cor, int x_cor) {
	int top;
	int bot;
	int left;
	int right;

	if (x_cor + 1 >= map[y_cor].size() || x_cor - 1 < 0 || y_cor + 1 >= map.size() || y_cor - 1 < 0) // 0 score if at edge
		return 0;
	bot = 1;
	for (int y = y_cor + 1; y < map.size() - 1 && map[y][x_cor] < map[y_cor][x_cor]; y++) // look down
		bot++;
	top = 1;
	for (int y = y_cor - 1; y > 0 && map[y][x_cor] < map[y_cor][x_cor]; y--) // look up
		top++;
	right = 1;
	for (int x = x_cor + 1; x < map[y_cor].size() - 1 && map[y_cor][x] < map[y_cor][x_cor]; x++) // look right
		right++;
	left = 1;
	for (int x = x_cor - 1; x > 0 && map[y_cor][x] < map[y_cor][x_cor]; x--) // look left
		left++;
	
	// std::cout << "target: " << map[y_cor][x_cor] << ", left: " << left << ", right: " << right
	// 		  << ", up: " << top << ", bot: " << bot << "\n";
	return left * right * top * bot;
}

int highest_scenic_score(std::string path)
{
	std::ifstream					inFile;
	std::vector<std::vector<int>>	map;
	int								max;
	int								num;

	inFile.open(path);
	map = generate_map(inFile);
	max = 0;
	for (int y = 0; y < map.size(); y++) {
		for (int x = 0; x < map[y].size(); x++) {
			num = scenic_score(map, y, x);
			if (num > max)
				max = num;
		}
	}
	inFile.close();
	return max;
}

int main(int argc, char** argv)
{
	std::string path;
	int			result;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	result = highest_scenic_score(path);
	std::cout << "Result:\n"<< result << "\n";
}
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

int	map_count(std::vector<std::vector<int>> &map, int target) {
	int ret;

	ret = 0;
	for (std::vector<int> &row : map){
		for (int &val : row) {
			if (val == target)
				ret++;
		}
	}
	return ret;
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

int total_visible_trees(std::string path)
{
	std::ifstream					inFile;
	std::vector<std::vector<int>>	map;
	std::vector<std::vector<int>>	status;
	int								ret;

	inFile.open(path);
	map = generate_map(inFile);
	status = process_map(map);
	std::cout << "Status:\n";
	map_print(status);
	ret = map_count(status, 1) + map_count(status, 2) + map_count(status, 3) + map_count(status, 4);
	inFile.close();
	return ret;
}

int main(int argc, char** argv)
{
	std::string path;
	int			result;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	result = total_visible_trees(path);
	std::cout << "Result:\n"<< result << "\n";
}

// int main()
// {
//     // Open the input file
//     std::ifstream inFile("files/input.txt");

//     // Generate the map from the input file
//     std::vector<std::vector<int>> map = generate_map(inFile);

//     // Close the input file
//     inFile.close();

//     // Print the map to the console
//     print_map(map);

//     return 0;
// }

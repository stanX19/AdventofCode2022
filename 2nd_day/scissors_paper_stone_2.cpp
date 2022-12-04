#include <iostream>
#include <fstream>
#include <string>
#include <map>

int evaluate(char opponent, char status)
{
	static std::map<char, int> game_score = 
	{
		{'X', 0},  // lose
		{'Y', 3},  // draw
		{'Z', 6}   // win
	};
	static std::map<char, std::map<char, int>> play_score = 
	{
		{'A', {{'X', 3}, {'Y', 1}, {'Z', 2}}},  // A n X == Rock == 3
		{'B', {{'X', 1}, {'Y', 2}, {'Z', 3}}},
		{'C', {{'X', 2}, {'Y', 3}, {'Z', 1}}}
	};
	
	return game_score[status] + play_score[opponent][status];

}

int total_score(std::string path)
{
	std::ifstream	inFile;
	char			buf[5];
	int				ret;

	ret = 0;
	inFile.open(path);
	while (!inFile.eof())
	{
		inFile.getline(buf, 5);
		ret += evaluate(buf[0], buf[2]);
	}
	inFile.close();
	return ret;
}

int main(int argc, char** argv)
{
	std::string path;
	int score;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	score = total_score(path);
	std::cout << score << "\n";
}
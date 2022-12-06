#include <iostream>
#include <fstream>
#include <string>

bool overlaps(int elfA[2], int elfB[2])
{
	if (elfA[0] <= elfB[0] && elfA[1] >= elfB[0])
		return true;
	if (elfA[0] >= elfB[0] && elfA[0] <= elfB[1])
		return true;
	return false;
}

int total_overlap(std::string path)
{
	std::ifstream	inFile;
	std::string		buf;
	int 			elfA[2];
	int 			elfB[2];
	int				ret;

	ret = 0;
	inFile.open(path);
	while (!inFile.eof())
	{
		std::getline(inFile, buf, '-');
		elfA[0] = std::stoi(buf);
		std::getline(inFile, buf, ',');
		elfA[1] = std::stoi(buf);
		std::getline(inFile, buf, '-');
		elfB[0] = std::stoi(buf);
		std::getline(inFile, buf, '\n');
		elfB[1] = std::stoi(buf);
		std::cout << '[' << elfA[0] << ", " << elfA[1] << "], "
				  << '[' << elfB[0] << ", " << elfB[1] << "]\n";
		if (overlaps(elfA, elfB))
		{
			std::cout << "overlaps\n";
			ret += 1;
		}
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
	score = total_overlap(path);
	std::cout << score << "\n";
}
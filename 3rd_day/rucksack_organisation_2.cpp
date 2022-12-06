#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

int evaluate_piriority(char c)
{
	if ('a' <= c and c <= 'z')
		return (c % 97) + 1;
	else if ('A' <= c and c <= 'Z')
		return (c % 65) + 27;
	return (int)0x80000000;
}

char common_character(std::string bagA, std::string bagB, std::string bagC)
{
	std::string::iterator	iterA;
	std::string::iterator	iterB;
	std::string::iterator	iterC;

	for (iterA = bagA.begin(); iterA != bagA.end(); iterA++)
	{
		for (iterB = bagB.begin(); iterB != bagB.end(); iterB++)
		{
			//std::cout << *iterA << " | " << *iterB << '\n';
			if (*iterA == *iterB)
			{
				for (iterC = bagC.begin(); iterC != bagC.end(); iterC++)
				{	
					if (*iterA == *iterC)
						return *iterA;
				}
			}
		}
	}

	std::cout << "Warning: no match!\n";
	return 0;
}

int total_piriority(std::string path)
{
	std::ifstream	inFile;
	std::string		bagA;
	std::string		bagB;
	std::string		bagC;
	int				ret;

	ret = 0;
	inFile.open(path);
	while (!inFile.eof())
	{
		std::getline(inFile, bagA);
		std::getline(inFile, bagB);
		std::getline(inFile, bagC);
		if (bagA.back() == '\r')
		{
			bagA.pop_back();
			bagB.pop_back();
			bagC.pop_back();
		}
		ret += evaluate_piriority(common_character(bagA, bagB, bagC));
		std::cout << bagA << " | " << bagB << " | " << bagC << '\n';
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
	score = total_piriority(path);
	std::cout << score << "\n";
}
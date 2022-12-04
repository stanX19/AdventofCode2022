#include <iostream>
#include <iterator>
#include <fstream>
#include <string>

int evaluate_piriority(char c)
{
	if ('a' < c and c < 'z')
		return (c % 97) + 1;
	return (c % 65) + 27;
}

char common_character(std::string compA, std::string compB)
{
	std::string::iterator	iterA;
	std::string::iterator	iterB;

	for (iterA = compA.begin(); iterA != compA.end(); iterA++)
	{
		for (iterB = compB.begin(); iterB != compB.end(); iterB++)
		{
			//std::cout << *iterA << " | " << *iterB << '\n';
			if (*iterA == *iterB)
			{
				return *iterA;
			}
		}
	}

	return 0;
}

int total_piriority(std::string path)
{
	std::ifstream	inFile;
	std::string		compA;  // compartmentA
	std::string		compB;
	int				ret;

	ret = 0;
	inFile.open(path);
	while (!inFile.eof())
	{
		std::getline(inFile, compA);
		if (compA.back() == '\r')
			compA.pop_back();
		compB = compA.substr(compA.length() / 2, compA.length());
		compA = compA.substr(0, compA.length() / 2);
		//std::cout << compA << " | " << compB << '\n';
		ret += evaluate_piriority(common_character(compA, compB));
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
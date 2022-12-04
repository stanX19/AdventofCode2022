#include <iostream>
#include <fstream>
#include <string>

int max_calories(std::string path)
{

	std::ifstream	inputFile;
	std::string		buf;
	int				max;
	int				cur;

	cur = 0;
	max = 0;
	inputFile.open(path);
	if (not inputFile.is_open())
		return -1;
	while (std::getline(inputFile, buf))
	{
		if (buf.length() > 0 and buf[0] != '\r') // if line is empty there is still a '\r' character at the end
			cur += std::stoi(buf);
		else
		{
			if (cur > max)
				max = cur;
			cur = 0;
		}
	}
	inputFile.close();
	return max;
}

int main(int argc, char**argv)
{
	std::string path;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	std::cout << max_calories(path) << '\n';
}
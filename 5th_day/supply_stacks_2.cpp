#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void process_command(std::string str, std::vector<std::string> &stacks)
{
    size_t	start;
	int		count;
	int		src;
	int		dst;
	char	c;

	start = 5;  // "move 4"
	count = std::stoi(&(str[start]));
	start = str.find(" from ", start + 1) + 6;  // "4 from 1"
	src = std::stoi(&(str[start])) - 1;
	start = str.find(" to ", start + 1) + 4;  // "1 to 2"
	dst = std::stoi(&(str[start])) - 1;

	stacks[dst] += stacks[src].substr(stacks[src].length() - count, count);
	stacks[src].erase(stacks[src].length() - count, count);
}

std::vector<std::string> generate_stacks(std::ifstream &inFile)
{
	std::string					line;
	std::vector<std::string>	ret;
	size_t						idx;
	
	while (std::getline(inFile, line) && !line.empty())
	{
		std::cout << line << "\n";
		idx = line.find_first_of('[', 0);
		while (idx != line.npos)
		{
			while (idx / 4 >= ret.size())
				ret.push_back("");
			ret[idx / 4].insert(0, 1, line[idx + 1]);
			idx = line.find_first_of('[', idx + 1);
		}
	}
	return ret;
}

std::string top_of_stack(std::string path)
{
	std::ifstream				inFile;
	std::string					buf;
	std::vector<std::string>	stacks;
	std::string					ret;

	inFile.open(path);
	stacks = generate_stacks(inFile);
	while (!inFile.eof())
	{
		std::getline(inFile, buf);
		for (const std::string& s : stacks) {
			std::cout << s << std::endl;
		}
		std::cout << buf << "\n";
		process_command(buf, stacks);
	}
	inFile.close();
	for (std::string &stack : stacks) {
		ret.push_back(stack.back());
	}
	return ret;
}

int main(int argc, char** argv)
{
	std::string path;
	std::string result;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	result = top_of_stack(path);
	std::cout << "Result:\n"<< result << "\n";
}

// int main()
// {
//     // open an input file stream
//     std::ifstream inFile("files/input.txt");

//     // generate the stacks from the input file
//     std::vector<std::string> stacks = generate_stacks(inFile);

//     // print the stacks
//     for (const std::string &stack : stacks)
//     {
//         std::cout << stack << "\n";
//     }

//     return 0;
// }
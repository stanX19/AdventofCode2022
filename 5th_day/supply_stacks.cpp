#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void process_command(std::string str, int* count, int* src, int* dst)
{

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
			ret[idx / 4].push_back(line[idx + 1]);
			idx = line.find_first_of('[', idx + 1);
		}
	}
	return ret;
}

int top_of_stack(std::string path)
{
	std::ifstream	inFile;
	std::string		buf;
	int 			count;
	int 			src;
	int				dst;
	int				ret;

	ret = 0;
	inFile.open(path);
	while (!inFile.eof())
	{
		std::getline(inFile, buf);
		
	}
	inFile.close();
	return ret;
}

// int main(int argc, char** argv)
// {
// 	std::string path;
// 	std::string result;

// 	if (argc == 1)
// 		path = "files/input.txt";
// 	else
// 		path = argv[1];
// 	result = top_of_stack(path);
// 	std::cout << result << "\n";
// }

int main() {
  std::ifstream inFile("files/input.txt");
  std::vector<std::string> lines;

  lines = generate_stacks(inFile);
  for (const std::string& line : lines) {
    std::cout << line << std::endl;
  }
  return 0;
}
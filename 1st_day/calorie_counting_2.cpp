#include <iostream>
#include <fstream>
#include <string>

void swap(int* a, int* b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void refresh_top3(int arr[3], int cur)
{
	int idx;

	idx = 0;
	if (arr[idx] < cur)
		swap(arr + idx, &cur);
	while (idx < 2)
	{
		if (arr[idx] > arr[idx + 1])
			swap(arr + idx, arr + idx + 1);
		idx++;
	}
}

int max_calories(std::string path)
{

	std::ifstream	inputFile;
	std::string		buf;
	int				top3[3];  // [no3, no2, no1]
	int				cur;

	cur = 0;
	inputFile.open(path);
	if (not inputFile.is_open())
		return -1;
	while (!inputFile.eof())
	{
		// read file by line until a empty carrige return
		while (std::getline(inputFile, buf) and buf.length() > 0 and buf[0] != '\r')
			cur += std::stoi(buf);
		refresh_top3(top3, cur);
		cur = 0;
	}
	inputFile.close();
	return top3[0] + top3[1] + top3[2];
}

int main(int argc, char** argv)
{
	std::string path;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	std::cout << max_calories(path) << '\n';
}
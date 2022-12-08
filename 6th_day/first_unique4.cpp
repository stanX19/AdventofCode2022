#include <iostream>
#include <fstream>
#include <string>

bool all_unique(const std::string& str, size_t start_idx, size_t n)
{
    for (size_t i = start_idx; i < start_idx + n; i++)
    {
        for (size_t j = i + 1; j < start_idx + n; j++)
        {
            if (str[i] == str[j])
            {
                return false;
            }
        }
    }
    return true;
}

size_t first_n_unique_char(const std::string& line, size_t n)
{
    for (size_t i = 0; i < line.size() - n; i++)
    {
        if (all_unique(line, i, n))
        {
            return i + n;
        }
    }
    return -1;
}

int main(int argc, char** argv)
{
    std::string path;
    std::string line;
    std::ifstream inFile;

    if (argc == 1)
    {
        path = "files/input.txt";
    }
    else
    {
        path = argv[1];
    }

    inFile.open(path);
    while (!inFile.eof())
    {
        std::getline(inFile, line);
        size_t index = first_n_unique_char(line, 4);
        std::cout << index << "\n";
    }
    inFile.close();
}
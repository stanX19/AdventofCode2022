#include <iostream>
#include <fstream>
#include <string>
#include <deque>


bool    all_unique(std::deque<char> str, size_t n){
    for (size_t i = 0; i < n; i++) {
        for (size_t j = i + 1; j < n; j++) {
            //std::cout << "i: " << str[i] << " | j: " << str[j] << std::endl;
            if (str[i] == str[j])
                return 0;
        }
    }
    return 1;
}

size_t  first_n_unique_char(std::string line, size_t n)
{
	std::deque<char>    buf;
    char                c;
	size_t			    idx;

	idx = 0;
	while (line[idx])
	{
        c = line[idx];
        buf.push_back(c);
        //std::cout << "running: " << c << std::endl;
        if (buf.size() > n) {
            buf.pop_front();
            if (all_unique(buf, n)){
	            return idx;
            }
        }
		idx++;
	}
	return -1;
}


int main(int argc, char** argv)
{
	std::string     path;
    std::string     line;
    std::ifstream   inFile;
	size_t          index;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
    
    inFile.open(path);
    while (!inFile.eof()){
        std::getline(inFile, line);
        index = first_n_unique_char(line, 14) + 1;
        std::cout << index << "\n";
    }
    inFile.close();
}
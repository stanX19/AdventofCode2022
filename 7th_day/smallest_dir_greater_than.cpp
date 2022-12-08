#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <string>
#include <sstream>


class Directory {
	private:
		size_t	size;
		bool	calculated;
	public:
		std::string							name;
		std::map<std::string, Directory*>	subdirectories;
		std::map<std::string, size_t>		files;

		Directory(std::string name, Directory* parent = nullptr) : name(name) {
			addSubdirectory(parent, "..");
			size = 0;
		}

		void addSubdirectory(Directory* subdirectory, std::string name = "") {
			if (name == "")
				name = subdirectory->name;
			if (files.count(name) == 0)
				subdirectories[name] = subdirectory;
			else
				std::cout << "Error: Directory " << name << " already exist\n";
		}
		void addFile(std::string file, size_t size) {
			if (files.count(file) == 0)
    			files[file] = size;
			else
				std::cout << "Error: File " << file << " already exist\n";
		}

		size_t getFinalSize() {
			if (calculated)
				return size;
			for (const std::pair<std::string, size_t>& entry : files) {
				size += entry.second;
			}
			for (const std::pair<std::string, Directory*>& entry : subdirectories) {
				if (entry.first != "..")
					size += entry.second->getFinalSize();
			}
			calculated = true;
			return size;
		}

		void list() {
			std::cout << "Directory: " << name << std::endl;
			std::cout << "Subdirectories: " << std::endl;
			for (const std::pair<std::string, Directory*>& entry : subdirectories) {
				std::cout << " - " << entry.first << std::endl;
			}
			std::cout << "Files: " << std::endl;
			for (const std::pair<std::string, size_t>& entry : files) {
				std::cout << " - " << entry.first << " (" << entry.second << " bytes)" << std::endl;
			}
		}

		void delete_dir(){
			for (const std::pair<std::string, Directory*> &pair : subdirectories){
				if (pair.first != "..") {
					(pair.second)->delete_dir();
				}
			}
			delete this;
		}
};

std::vector<std::string> stringToVector(std::string &str)
{
	std::vector<std::string> vec;
    std::stringstream ss(str);

    while (ss >> str)
        vec.push_back(str);

    return vec;
}

Directory* smallest_dir_greater_than(Directory *cwd, size_t min_size){
	size_t		smallest;
	size_t		temp_size;
	Directory	*subdir;
	Directory	*ret;

	smallest = -1;  // max value
	ret = nullptr;
	for (const std::pair<std::string, Directory*> &pair : cwd->subdirectories){
		if (pair.first != "..") {
			subdir = smallest_dir_greater_than(pair.second, min_size);  // if there is a dir that satisfies
			if (subdir) {
				temp_size = subdir->getFinalSize();
				if (temp_size < smallest) {
					smallest = temp_size;
					ret = subdir;
				}
			}
		}
	}
	if (cwd->getFinalSize() < smallest && cwd->getFinalSize() >= min_size)
		ret = cwd;
	return ret;
}

Directory* generate_root_from_file(std::string path) {
	std::ifstream				inFile;
	std::string					line;
	std::vector<std::string>	words;
	Directory					*root;
	Directory					*cwd;

	root = new Directory("/");
	inFile.open(path);
	while (std::getline(inFile, line))
	{
		std::stringstream lineStream(line);
		//std::cout << line << "\n";
		words = stringToVector(line);

		//std::cout << words[0] << '\n';

		if (words[0] == "$") {
			if (words[1] == "cd") {
				if (words[2] == "/")
					cwd = root;
				else
					cwd = cwd->subdirectories[words[2]]; // cd into that directory
			}
		}
		else if (words[0] == "dir") {
			Directory* subdir = new Directory(words[1], cwd); // name, parent_dir
			cwd->addSubdirectory(subdir); // subdir, name(optional)
		}
		else // word is an ingteger
			cwd->addFile(words[1], std::stoi(words[0]));
	}
	inFile.close();
	return root;
}


std::string smallest_file_name(std::string path)
{
	Directory	*root;
	size_t		needed_size;
	Directory	*result;
	std::string	ret;

	root = generate_root_from_file(path);
	//root->list();
	//std::cout << "dir a size = " << root->subdirectories[std::string("a")]->getFinalSize() << "\n";
	needed_size = root->getFinalSize() - 40000000;
	std::cout << "root size: " << root->getFinalSize() << '\n';
	std::cout << "needed size: " << needed_size << '\n';
	result = smallest_dir_greater_than(root, needed_size);
	if (result)
		ret = result->name;
	else
		ret = "None satisfies";
	std::cout << ret << " size: " << result->getFinalSize() << '\n';
	root->delete_dir();
	return ret;
}


int main(int argc, char** argv)
{
	std::string path;
	std::string	result;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	result = smallest_file_name(path);
	std::cout << "Result:\n"<< result << "\n";
}
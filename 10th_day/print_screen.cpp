#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <sstream>
#include <string>

class SignalReader {
public:
    SignalReader(const std::string& path) :
        in_file(path)
    {
        load_next_signal();
    }

    char next() {
		if (cycle_remaining == 0)
			load_next_signal();
		if (--cycle_remaining == 0)
			return signal_value;
        return 0;
    }

    bool good() const { return cycle_remaining >= 0 || !in_file.eof(); }

private:
    std::ifstream in_file;
	int signal_value;
    int cycle_remaining;

    void load_next_signal() {
		std::string command;

        if (in_file.eof()) {
            return;
        }
        in_file >> command;
		if (command == "addx") {
			in_file >> signal_value;
			cycle_remaining = 2;
		}
		else {
			signal_value = 0;
        	cycle_remaining = 1;
		}
    }
};

std::string total_signal_strength(std::string path)
{
	SignalReader		signal(path);
	std::stringstream	screen;
	int					cycle;
	int					value;
	
	cycle = 0;
	value = 1;
	while (cycle < 240 && signal.good()) {
		// during cycle
		cycle++;
		int index = cycle - 1;
		if (index % 40 >= value - 1 && index % 40 <= value + 1)
			screen << '#';
		else
			screen << '.';
		if (cycle % 40 == 0)
			screen << '\n';
		// after cycle
		value += signal.next();
	}
	return screen.str();
}

int main(int argc, char** argv)
{
	std::string path;
	std::string	result;

	if (argc == 1)
		path = "files/input.txt";
	else
		path = argv[1];
	result = total_signal_strength(path);
	std::cout << "Result:\n"<< result << "\n";
}
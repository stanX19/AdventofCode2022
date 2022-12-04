#include <iostream>
#include <string>

void swap(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int main(void)
{
	std::string	line;
	int			age;

	line = "Hello world!";
	std::cout << line.back();
	return 0;
}
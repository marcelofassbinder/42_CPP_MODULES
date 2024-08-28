#include <iostream>
#include <cstring>

int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
		{
			for(size_t j = 0; j < std::strlen(argv[i]); j++)
				argv[i][j] = std::toupper(argv[i][j]);
			std::cout << argv[i];
		}
	}
	else
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	std::cout << "\n";
}
#include <iostream>
#include <fstream>

int check_input(int argc, char **argv, std::ifstream &infile) {
	
	if (argc != 4) {
		std::cerr << "Error\nThe numbers of arguments must be 4" << std::endl;
		return 0;
	}
	if (!infile.is_open()){
		std::cerr << "Error\nIt's not possible to open: "<< argv[1] << std::endl;
		return 0;
	}
	std::string s1(argv[2]);
	std::string s2(argv[3]);
	if (s1.empty() || s2.empty()) {
		std::cerr << "Error\nOne or more arguments are invalid" << std::endl;
		return 0;
	}
	return 1;
}

int main(int argc, char **argv) {
	
	std::ifstream infile(argv[1]);
	
	if (!check_input(argc, argv, infile))
		return 1;

	std::string s1 (argv[2]);
	std::string s2 (argv[3]);
	std::string lineFromFile;
	std::string contentFromFile;

	while (std::getline(infile, lineFromFile)){
			contentFromFile+= lineFromFile + "\n";
	}
	infile.close();
	size_t found = contentFromFile.find(s1, 0);
	while (found != std::string::npos) {
		contentFromFile.erase(found, s1.length());
		contentFromFile.insert(found, s2);
		found = contentFromFile.find(s1, found + s2.length());
	}

	std::string newFileName (argv[1]);
	std::ofstream outfile(newFileName.append(".replace").c_str());
	outfile << contentFromFile;
	outfile.close();
}
 
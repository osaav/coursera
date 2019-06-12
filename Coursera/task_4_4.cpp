#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream input("input.txt");
	if (input) {
		std::string line;
		while (getline(input, line)) {
			std::cout << line << std::endl;
		}
	}
	int n;
	std::cin >> n;
	return 0;
}
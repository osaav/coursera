#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::ifstream input("input.txt");
	if (input) {
		std::ofstream output("output.txt");
		std::string line;
		while (getline(input, line)) {
			output << line << "\n";
		}
	}
}
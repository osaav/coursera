#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <sstream>

int main() {
	std::ifstream input("input.txt");
	if (input) {
		int N, M;
		input >> N >> M;
		std::string line;
		input.ignore(1);
		int i;
		for (int i = 0; i < N; ++i) {
			std::string line;
			std::getline(input, line);
			std::stringstream ss(line);
			for (int j = 0; j < M; ++j) {
				std::string str_var;
				std::getline(ss, str_var, ',');
				int var = std::stoi(str_var);
				std::cout << std::setw(10) << var;
				if (j != M - 1) {
					std::cout << ' ';
				}
			}
			if (i != N - 1) {
				std::cout << std::endl;
			}
		}
	}
	int n;
	std::cin >> n;
	return 0;
}
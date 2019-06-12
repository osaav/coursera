#include <fstream>
#include <iomanip>
#include <iostream>

int main() {
	std::ifstream input("input.txt");
	if (input) {
		std::cout << std::fixed << std::setprecision(3);
		double var;
		while (input >> var) {
			std::cout << var << std::endl;
		}
	}
	int n;
	std::cin >> n;
	return 0;
}
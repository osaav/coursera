#include <iostream>
#include <exception>
#include <string>
#include <sstream>

void EnsureEqual(const std::string& left, const std::string& right) {
	if (left != right) {
		std::ostringstream out;
		out << left << " != " << right;
		throw std::runtime_error(out.str());
	}
}

int main() {
	try {
		EnsureEqual("C++ White", "C++ White");
		EnsureEqual("C++ White", "C++ Yellow");
	}
	catch(std::runtime_error& e) {
		std::cout << e.what() << std::endl;
	}
	int n;
	std::cin >> n;
	return 0;
}
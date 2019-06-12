#include <iostream>
#include <string>
#include <vector>

struct Date {
	int d = 0;
	int m = 0;
	int y = 0;
};

struct Student {

public:
	Student(const std::string& new_name, const std::string& new_surname, int new_d, int new_m, int new_y) {
		name = new_name;
		surname = new_surname;
		birth.d = new_d;
		birth.m = new_m;
		birth.y = new_y;
	}
	void PrintName() {
		std::cout << name << ' ' << surname << std::endl;
	}
	void PrintDate() {
		std::cout << birth.d << '.' << birth.m << '.' << birth.y << std::endl;
	}

private:
	std::string name;
	std::string surname;
	Date birth;
};

int main() {
	int n;
	std::cin >> n;
	std::vector<Student> students;
	for (int i = 0; i < n; ++i) {
		std::string name, surname;
		int d, m, y;
		std::cin >> name >> surname >> d >> m >> y;
		students.push_back({name, surname, d, m, y});
	}
	int m;
	std::cin >> m;
	for (int i = 0; i < m; ++i) {
		std::string cmd;
		int nbr;
		std::cin >> cmd >> nbr;
		if (cmd == "name" && nbr > 0 && nbr <= n) {
			students[nbr-1].PrintName();
		}
		else if (cmd == "date" && nbr > 0 && nbr <= n) {
			students[nbr-1].PrintDate();
		}
		else {
			std::cout << "bad request" << std::endl;
		}
	}
	std::cin >> n;
	return 0;
}
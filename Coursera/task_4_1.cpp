#include <iostream>
#include <string>

using namespace std;

struct Specialization {
	string value;
	explicit Specialization(const string& new_value) {
		value = new_value;
	}
};

struct Course {
	string value;
	explicit Course(const string& new_value) {
		value = new_value;
	}
};

struct Week {
	string value;
	explicit Week(const string& new_value) {
		value = new_value;
	}
};

struct LectureTitle {
	LectureTitle(const Specialization& new_specialization,
				 const Course& new_course,
				 const Week& new_week) {
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
	void OutTitle() {
		std::cout << specialization << std::endl << course << std::endl << week << std::endl;
	}

	string specialization;
	string course;
	string week;
};

int main() {

	LectureTitle title(
		Specialization("C++"),
		Course("White belt"),
		Week("4th")
	);
	title.OutTitle();

	int n;
	std::cin >> n;
	return 0;
}
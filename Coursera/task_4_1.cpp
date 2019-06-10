#include <iostream>
#include <string>

using namespace std;

struct LectureTitle {
public:
	struct Specialization {
		string value;
		explicit Specialization(string new_value) {
			value = new_value;
		}
	};

	struct Course {
		string value;
		explicit Course(string new_value) {
			value = new_value;
		}
	};

	struct Week {
		string value;
		explicit Week(string new_value) {
			value = new_value;
		}
	};

	LectureTitle(Specialization new_specialization, Course new_course, Week new_week) {
		specialization = new_specialization.value;
		course = new_course.value;
		week = new_week.value;
	}
	/*void OutTitle() {
		cout << specialization << endl << course << endl << week << endl;
	}*/
private:
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
/*	title.OutTitle();

	int n;
	cin >> n;*/
	return 0;
}
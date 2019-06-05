#include <iostream>
#include <map>
#include <string>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		hist[year].first_name = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		hist[year].last_name = last_name;
	}
	string GetFullName(int year) {
		fullname founded;
		for (auto item : hist) {
			if (item.first <= year) {
				if (item.second.first_name.length() != 0) {
					founded.first_name = item.second.first_name;
				}
				if (item.second.last_name.length() != 0) {
					founded.last_name = item.second.last_name;
				}
			}
			else {
				break;
			}
		}
		string res;
		if ((founded.first_name.length() != 0) && (founded.last_name.length() != 0)) {
			res = founded.first_name + " " + founded.last_name;
		}
		else if ((founded.first_name.length() == 0) && (founded.last_name.length() == 0)) {
			res = "Incognito";
		}
		else if (founded.first_name.length() == 0) {
			res = founded.last_name + " with unknown first name";
		}
		else if (founded.last_name.length() == 0) {
			res = founded.first_name + " with unknown last name";
		}
		return res;
	}

private:
	struct fullname {
		string first_name;
		string last_name;
	};
	map<int, fullname > hist;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullName(year) << endl;
	}

	int n;
	cin >> n;
	return 0;
}
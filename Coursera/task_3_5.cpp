#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		hist[year].first_name = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		hist[year].last_name = last_name;
	}

	struct fullname;
	fullname FindByHistory(int year) {
		fullname founded;
		for (auto item : hist) {
			if (item.first <= year) {
				if (!item.second.first_name.empty()) {
					if (!founded.first_name.empty()) {
						founded.first_name_hist.insert(founded.first_name_hist.begin(), founded.first_name);
					}
					founded.first_name = item.second.first_name;
				}
				if (!item.second.last_name.empty()) {
					if (!founded.last_name.empty()) {
						founded.last_name_hist.insert(founded.last_name_hist.begin(), founded.last_name);
					}
					founded.last_name = item.second.last_name;
				}
			}
			else {
				break;
			}
		}
		return founded;
	}

	string GetFirstNameHist(fullname founded) {
		string res = "";
		if (founded.first_name_hist.empty()) {
			return res;
		}
		res += " (";
		for (auto i : founded.first_name_hist) {
			res = res + i + ", ";
		}
		res = res.substr(0, res.size() - 2);
		res += ")";
		return res;
	}

	string GetLastNameHist(fullname founded) {
		string res = "";
		if (founded.last_name_hist.empty()) {
			return res;
		}
		res += " (";
		for (auto i : founded.last_name_hist) {
			res = res + i + ", ";
		}
		res = res.substr(0, res.size() - 2);
		res += ")";
		return res;
	}

	string GetFullName(int year) {
		fullname founded = FindByHistory(year);
		string res;
		if ((founded.first_name.empty()) && (founded.last_name.empty())) {
			res = "Incognito";
		}
		else if ((founded.first_name.empty())) {
			res = founded.last_name + " with unknown first name";
		}
		else if (founded.last_name.empty()) {
			res = founded.first_name + " with unknown last name";
		}
		else {
			res = founded.first_name + ' ' + founded.last_name;
		}
		return res;
	}

	string GetFullNameWithHistory(int year) {
		fullname founded = FindByHistory(year);
		string res;
		if ((founded.first_name.empty()) && (founded.last_name.empty())) {
			res = "Incognito";
		}
		else if ((founded.first_name.empty())) {
			res = founded.last_name + GetLastNameHist(founded) + " with unknown first name";
		}
		else if (founded.last_name.empty()) {
			res = founded.first_name + GetFirstNameHist(founded) + " with unknown last name";
		}
		else {
			res = founded.first_name + GetFirstNameHist(founded) + ' ' + founded.last_name + GetLastNameHist(founded);
		}
		return res;
	}

private:
	struct fullname {
		string first_name;
		string last_name;
		vector<string> first_name_hist;
		vector<string> last_name_hist;
	};
	map<int, fullname> hist;
};

int main() {
	Person person;

	person.ChangeFirstName(1965, "Polina");
	person.ChangeLastName(1967, "Sergeeva");
	for (int year : {1900, 1965, 1990}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1970, "Appolinaria");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1968, "Volkova");
	for (int year : {1969, 1970}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1990, "Polina");
	person.ChangeLastName(1990, "Volkova-Sergeeva");
	cout << person.GetFullNameWithHistory(1990) << endl;

	person.ChangeFirstName(1966, "Pauline");
	cout << person.GetFullNameWithHistory(1966) << endl;

	person.ChangeLastName(1960, "Sergeeva");
	for (int year : {1960, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeLastName(1961, "Ivanova");
	cout << person.GetFullNameWithHistory(1967) << endl;

	int n;
	cin >> n;
	return 0;
}
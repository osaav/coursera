#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> FindNameHistory(const map<int, string>& name_hist, int year) {
	if (year < name_hist.begin()->first) {
		return {};
	}
	vector<string> found_hist;
	for (const auto& item : name_hist) {
		if (item.first <= year && (found_hist.empty() || (found_hist.back() != item.second))) {
			found_hist.push_back(item.second);
		}
	}
	return found_hist;
}

string JoinHistNames(vector<string> name_hist) {
	if (name_hist.empty()) {
		return "";
	}
	reverse(begin(name_hist), end(name_hist));
	string joined_name = name_hist[0];
	for (int i = 1; i < name_hist.size(); ++i) {
		if (i == 1) {
			joined_name += " (";
		}
		else {
			joined_name += ", ";
		}
		joined_name += name_hist[i];
	}
	if (name_hist.size() > 1) {
		joined_name += ")";
	}
	return joined_name;
}

class Person {
public:
	Person(const string& first_name, const string& last_name, int new_birth_year) {
		birth_year = new_birth_year;
		first_name_hist[birth_year] = first_name;
		last_name_hist[birth_year] = last_name;
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year >= birth_year) {
			first_name_hist[year] = first_name;
		}
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= birth_year) {
			last_name_hist[year] = last_name;
		}
	}

	string GetFullName(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		const vector<string> first_name_hist = FindFirstNameHistory(year);
		const vector<string> last_name_hist = FindLastNameHistory(year);
		return first_name_hist.back() + " " + last_name_hist.back();
	}

	string GetFullNameWithHistory(int year) const {
		if (year < birth_year) {
			return "No person";
		}
		const string first_name = JoinHistNames(FindFirstNameHistory(year));
		const string last_name = JoinHistNames(FindLastNameHistory(year));
		return first_name + " " + last_name;
	}

private:
	vector<string> FindFirstNameHistory(int year) const {
		return FindNameHistory(first_name_hist, year);
	}
	vector<string> FindLastNameHistory(int year) const {
		return FindNameHistory(last_name_hist, year);
	}

	int birth_year;
	map<int, string> first_name_hist;
	map<int, string> last_name_hist;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanove");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	int n;
	cin >> n;
	return 0;
}
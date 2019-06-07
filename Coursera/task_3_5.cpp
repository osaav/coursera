#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

vector<string> FindNameHistory(const map<int, string>& name_hist, int year) {
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

string ComposeFullName(const string& first_name, const string& last_name) {
	if (first_name.empty() && last_name.empty()) {
		return "Incognito";
	}
	else if (first_name.empty()) {
		return last_name + " with unknown first name";
	}
	else if (last_name.empty()) {
		return first_name + " with unknown last name";
	}
	else {
		return first_name + " " + last_name;
	}
}

class Person {
public:
	void ChangeFirstName(int year, const string& first_name) {
		first_name_hist[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		last_name_hist[year] = last_name;
	}

	string GetFullName(int year) {
		const vector<string> first_name_hist = FindFirstNameHistory(year);
		const vector<string> last_name_hist = FindLastNameHistory(year);

		string first_name;
		string last_name;
		if (!first_name_hist.empty()) {
			first_name = first_name_hist.back();
		}
		if (!last_name_hist.empty()) {
			last_name = last_name_hist.back();
		}
		return ComposeFullName(first_name, last_name);
	}

	string GetFullNameWithHistory(int year) {
		const string first_name = JoinHistNames(FindFirstNameHistory(year));
		const string last_name = JoinHistNames(FindLastNameHistory(year));
		return ComposeFullName(first_name, last_name);
	}

private:
	vector<string> FindFirstNameHistory(int year) {
		return FindNameHistory(first_name_hist, year);
	}
	vector<string> FindLastNameHistory(int year) {
		return FindNameHistory(last_name_hist, year);
	}

	map<int, string> first_name_hist;
	map<int, string> last_name_hist;
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
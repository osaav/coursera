#include <iostream>
#include <map>
#include <string>

using namespace std;

void change_capital(map <string, string>& world, const string country, const string new_capital) {
	if (world.count(country) == 0) {
		world.insert(pair <string, string>(country, new_capital));
		cout << "Introduce new country " << country << " with capital "  << world[country];
	}
	else {
		if (world[country] == new_capital) {
			cout << "Country " << country << " hasn't changed its capital";
		}
		else {
			string old_capital = world[country];
			world[country] = new_capital;
			cout << "Country " << country << " has changed its capital from " << old_capital << " to " << world[country];
		}
	}
	cout << endl;
}

void rename(map <string, string>& world, const string old_country, const string new_country) {
	if (old_country == new_country || world.count(old_country) == 0 || world.count(new_country) != 0) {
		cout << "Incorrect rename, skip" << endl;
		return;
	}
	string capital = world[old_country];
	world.erase(old_country);
	world.insert(pair <string, string>(new_country, capital));
	cout << "Country " << old_country << " with capital " << capital << " has been renamed to " << new_country << endl;
}

void about(map <string, string> world, const string country) {
	if (world.count(country) == 0) {
		cout << "Country " << country << " doesn't exist" << endl;
		return;
	}
	cout << "Country " << country << " has capital " << world[country] << endl;
}

void dump(const map <string, string> world) {
	if (world.size() == 0) {
		cout << "There are no countries in the world" << endl;
		return;
	}
	for (auto item : world) {
		cout << item.first << "/" << item.second << endl;
	}
}

int main() {
	map <string, string> world;
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "CHANGE_CAPITAL") {
			string country, new_capital;
			cin >> country >> new_capital;
			change_capital(world, country, new_capital);
		}
		else if (cmd == "RENAME") {
			string old_country, new_country;
			cin >> old_country >> new_country;
			rename(world, old_country, new_country);
		}
		else if (cmd == "ABOUT") {
			string country;
			cin >> country;
			about(world, country);
		}
		else if (cmd == "DUMP") {
			dump(world);
		}
	}
	cin >> n;
	return 0;
}
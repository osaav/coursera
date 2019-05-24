#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

void new_bus(map<string, vector<string>>& table) {
	string bus;
	int count;
	cin >> bus >> count;
	table.insert(pair <string, vector<string>>(bus, vector<string>()));
	for (int j = 0; j < count; ++j) {
		string stop;
		cin >> stop;
		table[bus].push_back(stop);
	}
}

void buses_for_stop(map<string, vector<string>>& table) {

}

void stops_for_bus(map<string, vector<string>>& table) {

}

void all_buses(map<string, vector<string>>& table) {
	if (table.size() == 0) {
		cout << "No buses";
	}
	for (auto item : table) {
		cout << "Bus " << item.first << ": ";
		for (auto stop : item.second) {
			cout << stop << " ";
		}
	}
	cout << endl;
}

int main() {
	int n;
	map<string, vector<string>> table;
	cin >> n;
	for (int i = 0; i <= n; ++n) {
		string cmd;
		cin >> cmd;
		if (cmd == "ADD") {
			new_bus(table);
		}
		else if (cmd == "BUSES_FOR_STOP") {
			buses_for_stop(table);
		}
		else if (cmd == "STOPS_FOR_BUS") {
			stops_for_bus(table);
		}
		else if (cmd == "DUMP") {
			all_buses(table);
		}
	}
	cin >> n;
	return 0;
}
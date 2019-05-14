#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int cmd_nbr;
	vector<bool> is_nervous;

	cin >> cmd_nbr;
	for (int i = 0; i < cmd_nbr; ++i) {
		string op_code;
		cin >> op_code;
		if (op_code == "WORRY_COUNT") {
			// ������������ ���������� ��������� � ������� is_nervous, ������ true
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;
		}
		else {
			if (op_code == "WORRY" || op_code == "QUIET") {
				int pers_idx;
				cin >> pers_idx;
				// ��������� � ������� ����� ��� bool � ����� true ��� ������� WORRY,
				// ������� is_nervous[person_index] ������ ������ false ��� true
				// � ����������� �� operation_code
				is_nervous[pers_idx] = (op_code == "WORRY");
			}
			else if (op_code == "COME") {
				int pers_cnt;
				cin >> pers_cnt;
				// ����� resize ����� ��� ��������� ������ �������, ��� � �����������,
				// ������� ���������� ������������� ������ � �������������
				// � ������������� person_count �� �����
				is_nervous.resize(is_nervous.size() + pers_cnt, false);
			}
		}
	}
	cin >> cmd_nbr;
	return 0;
}
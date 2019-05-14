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
			// подсчитываем количество элементов в векторе is_nervous, равных true
			cout << count(begin(is_nervous), end(is_nervous), true) << endl;
		}
		else {
			if (op_code == "WORRY" || op_code == "QUIET") {
				int pers_idx;
				cin >> pers_idx;
				// выражение в скобках имеет тип bool и равно true для запроса WORRY,
				// поэтому is_nervous[person_index] станет равным false или true
				// в зависимости от operation_code
				is_nervous[pers_idx] = (op_code == "WORRY");
			}
			else if (op_code == "COME") {
				int pers_cnt;
				cin >> pers_cnt;
				// метод resize может как уменьшать размер вектора, так и увеличивать,
				// поэтому специально рассматривать случаи с положительным
				// и отрицательным person_count не нужно
				is_nervous.resize(is_nervous.size() + pers_cnt, false);
			}
		}
	}
	cin >> cmd_nbr;
	return 0;
}
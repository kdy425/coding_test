//น้มุ 11053
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_answer(vector<int>& num_list, const int& num) {
	vector<int> increase(num, 1);
	vector<int> decrease(num, 1);

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (num_list[i] > num_list[j]) {
				increase[i] = max(increase[i], increase[j] + 1);
			}
		}
	}

	reverse(num_list.begin(), num_list.end());

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (num_list[i] > num_list[j]) {
				decrease[i] = max(decrease[i], decrease[j] + 1);
			}
		}
	}

	vector<int> result(num);

	reverse(decrease.begin(), decrease.end());

	for (int i = 0; i < num; i++) {
		result[i] = increase[i] + decrease[i] - 1;
	}

	int max_value = *max_element(result.begin(), result.end());

	

	for (auto& n : result)
		cout << n << " ";
	cout << endl;

	

	return max_value;


}

int main() {
	int num;
	cin >> num;
	vector<int> num_list(num);

	for (int i = 0; i < num; i++)
		cin >> num_list[i];

	cout << get_answer(num_list, num);
}
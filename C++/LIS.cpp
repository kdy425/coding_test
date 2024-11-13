//น้มุ 11053
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int get_answer(const vector<int>& num_list, const int& num) {
	vector<int> result(num, 1);

	for (int i = 1; i < num; i++) {
		for (int j = 0; j < i; j++) {
			if (num_list[i] > num_list[j]) {
				result[i] = max(result[i], result[j] + 1);
			}
		}
	}

	int max_value = *max_element(result.begin(), result.end());
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
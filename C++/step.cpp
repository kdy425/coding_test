#include<iostream>
#include<vector>
using namespace std;

int find_max(const vector<int>& step_list, int step) {
	vector<int> result(step_list);
	if (step > 1) {
		result[2] = step_list[1] + step_list[2];

		for (int i = 3; i <= step; i++) {
			result[i] = max(result[i - 2], result[i - 3] + step_list[i - 1]) + step_list[i];
		}
	}

	return result[step];

}

int main() {
	int step;
	cin >> step;
	vector<int> step_list(step + 1, 0);

	for (int i = 1; i <= step; i++)
		cin >> step_list[i];

	cout << find_max(step_list, step);
}


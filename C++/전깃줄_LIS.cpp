//น้มุ 2565
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int solution(const vector<pair<int, int>> &pair, const int &line) {
	vector<int> result(line, 1);

	for (int i = 1; i < line; i++) {
		for (int j = 0; j < i; j++) {
			if (pair[i].second > pair[j].second) {
				result[i] = max(result[i], result[j] + 1);
			}
		}
	}

	int max = *max_element(result.begin(), result.end());
	return line - max;
}

int main() {
	int line;
	cin >> line;

	vector<pair<int, int>> pair;
	pair.reserve(line);

	for (int i = 0; i < line; i++) {
		int first, second;
		cin >> first >> second;
		pair.emplace_back(first, second);
	}

	sort(pair.begin(), pair.end());


	cout << solution(pair, line);
}

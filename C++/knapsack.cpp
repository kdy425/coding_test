//น้มุ 12865
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
int solution(const vector<pair<int, int>>& tools, const int num, const int weight) {
	vector<vector<int>> result(num + 1, vector<int>(weight + 1, 0));

	for (int i = 1; i <= num; i++) {
		for (int j = 1; j <= weight; j++) {
			if (tools[i - 1].first <= j) {
				result[i][j] = max(result[i - 1][j], result[i - 1][j - tools[i - 1].first] + tools[i - 1].second);
			}
			else {
				result[i][j] = result[i - 1][j];
			}
		}
	}

	return result[num][weight];
}
*/


//optimization
int solution(const vector<pair<int, int>>& tools, const int num, const int weight) {
	vector<int> result(weight + 1, 0);
	for (int i = 0; i < num; i++) {
		const int w = tools[i].first;
		const int v = tools[i].second;

		for (int j = weight; j >= w; j--) {
			result[j] = max(result[j], result[j - w] + v);

		}
	}
	return result[weight];
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num, weight;

	cin >> num >> weight;

	vector<pair<int, int>> tools;
	tools.reserve(num);

	int first, second;
	for (int i = 0; i < num; i++) {
		cin >> first >> second;
		tools.emplace_back(first, second);
	}

	cout << solution(tools, num, weight);


}
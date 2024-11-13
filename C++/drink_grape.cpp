//백준 2156
#include<iostream>
#include<vector>
using namespace std;

int drink(const vector<int>& cup, const int &count) {
	if (count == 1)
		return cup[0];
	if (count  == 2)
		return cup[0] + cup[1];

	vector<int> result(count, 0);
	result[0] = cup[0];
	result[1] = cup[0] + cup[1];
	result[2] = max(result[1], max(cup[1] + cup[2], cup[0] + cup[2]));  // 중첩 max를 사용하여 세 값을 비교
	
	
	for (int i = 3; i < count; i++) {
		result[i] = max(result[i - 1], max(result[i - 2] + cup[i], result[i - 3] + cup[i - 1] + cup[i]));
	}
	
	
	for (auto& n : result)
		cout << n << " ";
	cout << endl;
	
	return result[count - 1];
}

int main() {
	int count;
	cin >> count;

	vector<int> cup(count, 0);

	for (int i = 0; i < count; i++)
		cin >> cup[i];

	cout << drink(cup, count);

}
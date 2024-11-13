#include<iostream>
#include<vector>
//#include<algorithm>
using namespace std;

int func(const vector<int> num_list, int size) {
	int current = num_list[0];
	int total = num_list[0];

	for (int i = 1; i < size; i++) {
		current = max(current + num_list[i], num_list[i]);
		total = max(total, current);
		//current = total;
	}

	return total;
}

int main() {
	int size;
	cin >> size;
	
	vector<int> num_list(size);

	for (int i = 0; i < size; i++)
		cin >> num_list[i];

	cout << func(num_list, size);

}
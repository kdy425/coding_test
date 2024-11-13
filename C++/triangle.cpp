#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int dx[] = { 1, 1 };
const int dy[] = { 0, 1 };

void find_max(const vector<vector<int>> &matrix, vector<vector<int>> &temp, int size) {
	int sum = matrix[0][0];
	temp[0][0] = sum;
	//int col = 0, row = 0;
	for (int col = 0; col < size; col++) {
		for (int row = 0; row < size; row++) {
			for (int i = 0; i < 2; i++) {
				int nx = col + dx[i];
				int ny = row + dy[i];
				if(nx < size && ny < size)
					temp[nx][ny] = max(temp[nx][ny], temp[col][row] + matrix[nx][ny]);
				//col = nx;
				//row = ny;
			}
		}
	}
}


int main() {
	int size;
	cin >> size;

	vector<vector<int>> matrix(size, vector<int>(size, 0));
	vector<vector<int>> temp(size, vector<int>(size, 0));

	for (int i = 0; i < size; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> matrix[i][j];
		}
	}

	find_max(matrix, temp, size);

	/*
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size - (4 - i); j++) {
			cout << temp[i][j] << "\t";
		}
		cout << endl;
	}
	*/
	
	//int result = *max_element(temp[size - 1].begin(), temp[size - 1].end());

	int result = 0;
	for (int j = 0; j < size; j++) {
		result = max(result, temp[size - 1][j]);
	}
	
	cout << result;
	

}


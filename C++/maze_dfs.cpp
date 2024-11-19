//백준2178
#include<iostream>
#include<queue>
#include<vector>
#include<string>

using namespace std;
const int dx[] = { 0, 0, -1, 1 };
const int dy[] = { 1, -1, 0, 0 };

int solution(const vector<vector<int>>& matrix, int n, int m) {
	vector<vector<bool>> visited(n, vector<bool>(m, false));
	visited[0][0] = true;
	queue<pair<int, int>> queue;
	vector<vector<int>> dist(n, vector<int>(m, 0));

	queue.push({ 0, 0 });
	visited[0][0] = true;
	dist[0][0] = 1;

	while (!queue.empty()) {
		int x = queue.front().first;
		int y = queue.front().second;

		queue.pop();

		if (x == n - 1 && y == m - 1)
			return dist[x][y];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && matrix[nx][ny] == 1) {
				queue.push({ nx, ny });
				visited[nx][ny] = true;
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	cin.ignore();	//개행 문자 제거

	vector<vector<int>> matrix(n, vector<int>(m));

	for (int i = 0; i < n; i++) {
		string line;
		getline(cin, line);
		for (int j = 0; j < m; j++) {
			matrix[i][j] = line[j] - '0';	//문자를 정수로 변환
		}
	}
	cout << solution(matrix, n, m);
}
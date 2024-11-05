#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int matrix[20][20];
bool visited[20][20];
const int dx[4] = { 0, 1, 0, -1 };
const int dy[4] = { 1, 0, -1, 0 };
int n, m;
vector<pair<int, int>> best_path;
vector<pair<int, int>> current_path;
vector<int> results;

bool can_move(int nx, int ny) { // �־��� ��ǥ�� ���� ���� �ִ��� Ȯ��
    return nx >= 0 && nx < n && ny >= 0 && ny < n;
}

int dfs(int x, int y, int move, int sum) {
    if (move == 3) {
        return sum;
    }
    int max_sum = sum;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (can_move(nx, ny) && !visited[nx][ny]) {
            visited[nx][ny] = true;
            current_path.push_back({ nx, ny });
            int total_sum = dfs(nx, ny, move + 1, sum + matrix[nx][ny]);
            if (results.empty() || results.back() < total_sum) {
                results.push_back(total_sum);
                max_sum = total_sum;
                if (move == 2) {
                    best_path = current_path;
                }
            }
            current_path.pop_back();
            visited[nx][ny] = false;
        }
    }
    return results.back();
}

int find_max(int x, int y) {    //�־��� ���������� dfs�� �����Ͽ� �ִ� ��Ȯ���� ã�´�.
    int start_fruit = matrix[x][y];
    visited[x][y] = true;
    matrix[x][y] = 0;
    results.clear();
    results.push_back(start_fruit);
    int max_fruit = dfs(x, y, 0, start_fruit);
    visited[x][y] = false;

    for (const auto& p : best_path) {
        matrix[p.first][p.second] = 0;  //������ ��θ� ã�� �ش� ����� ������ 0���� �����. - ��Ȯ��
    }
    current_path.clear();
    return max_fruit;
}

int main() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matrix[i][j];
        }
    }

    vector<pair<int, int>> friends(m);  //ģ�� �·� �Է¹��� ����
    for (int i = 0; i < m; i++) {
        cin >> friends[i].first >> friends[i].second;
        friends[i].first--; friends[i].second--;  // 0-based �ε����� ��ȯ
    }

    vector<int> order(m);
    for (int i = 0; i < m; i++) order[i] = i;

    int answer = 0;
    do {
        int tmp[20][20];
        memcpy(tmp, matrix, sizeof(matrix));    //matrix �ʱ� ���� �����صα�
        int current_sum = 0;
        for (int i : order) {
            current_sum += find_max(friends[i].first, friends[i].second);
        }
        answer = max(answer, current_sum);
        memcpy(matrix, tmp, sizeof(tmp));   //�����ص� matrix �ʱ� ���� �����ϱ�
    } while (next_permutation(order.begin(), order.end())); //��� ����� ���� Ž��

    cout << answer << endl;
    return 0;
}



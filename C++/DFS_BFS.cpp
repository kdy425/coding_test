#include<iostream>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
using namespace std;

void dfs(vector<vector<int>>& graph, int num, int start) {
	stack<int> stack;
	stack.push(start);
	int n = graph.size();
	vector<bool> visited(n + 1, false);
	while (!stack.empty()) {
		int current = stack.top();
		stack.pop();
		if (!visited[current]) {
			visited[current] = true;
			cout << current << " ";

			sort(graph[current].begin(), graph[current].end(), greater<int>());

			for (int next : graph[current]) {
				if (!visited[next])
					stack.push(next);
			}
		}

	}
}

void bfs(vector<vector<int>>& graph, int num, int start) {
	queue<int> queue;
	queue.push(start);
	int n = graph.size();
	vector<bool> visited(n + 1, false);
	while (!queue.empty()) {
		int current = queue.front();
		queue.pop();
		if (!visited[current]) {
			visited[current] = true;
			cout << current << " ";
			sort(graph[current].begin(), graph[current].end());
			for (int next : graph[current]) {
				if (!visited[next])
					queue.push(next);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int num, line, start;

	cin >> num >> line >> start;

	vector<vector<int>> graph(num + 1);
	int to, from;

	for (int i = 0; i < line; i++) {
		cin >> to >> from;
		graph[to].push_back(from);
		graph[from].push_back(to);
	}

	dfs(graph, num, start);
	cout << endl;
	bfs(graph, num, start);

}
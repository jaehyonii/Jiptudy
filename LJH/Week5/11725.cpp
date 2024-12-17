#include <bits/stdc++.h>
using namespace std;

int main() {
	int n = 0;
	cin >> n;
	vector<vector<int>> adj(n+1);
	for (int i = 1; i < n; i++) {
		int a = 0, b = 0;
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	queue<int> q;
	vector<int>parent(n+1, 0);
	parent[1] = -1;
	q.push(1);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		for (int i = 0; i < adj[now].size(); i++) {
			int next = adj[now][i];
			if (parent[next]==0) {
				parent[next] = now;
				q.push(next);
			}
		}
	}
	for (int i = 2; i <= n; i++) cout << parent[i] << "\n";

	return 0;
}
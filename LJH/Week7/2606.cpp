#include <bits/stdc++.h>
using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited, int& count) {
    visited[node] = true;
    count++;
    for (int i = 0; i < graph[node].size(); i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, graph, visited, count);
        }
    }
}

int main() {
    int n = 0, m = 0;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));

    for (int i = 0; i < m; i++) {
        int a = 0, b = 0;
        cin >> a >> b;
        graph[a][b] = 1;
        graph[b][a] = 1;
    }

    vector<bool> visited(n + 1, false);

    int count = 0;
    dfs(1, graph, visited, count);

    cout << count - 1 << endl;
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main() {
    int tree[500][500];
    int n, maxx;
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++)
            cin >> tree[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i == j && i == 0)
                continue;
            if (j == 0)
                tree[j][i] = tree[i][j] + tree[j][i-1];
            else if (i != 0 && i == j)
                tree[i][j] += tree[i-1][j-1];
            else
                tree[j][i] = max(tree[j][i-1], tree[j-1][i-1]) + tree[i][j];
        }
    }
    maxx = 0;
    for (int i = 0; i < n; i++)
        maxx = max(maxx, tree[i][n-1]);
    cout << maxx;
    return 0;
}
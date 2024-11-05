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
                tree[i][j] += tree[i-1][j];
            else if (i != 0 && i == j)
                tree[i][j] += tree[i-1][j-1];
            else
                tree[i][j] += max(tree[i-1][j], tree[i-1][j-1]);
        }
    }
    maxx = 0;
    for (int j = 0; j < n; j++)
        maxx = max(maxx, tree[n-1][j]);
    cout << maxx;
    return 0;
}
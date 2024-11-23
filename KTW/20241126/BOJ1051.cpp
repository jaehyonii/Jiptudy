#include <bits/stdc++.h>

using namespace std;

int v[50][50];
int n, m;

int rec(void) {
    int min = n < m ? n : m;
    
    for (int r = min; r > 1; r--) {
        for (int i = 0; i+r <= n; i++) {
            for (int j = 0; j+r <= m; j++) {
                if (v[i][j] == v[i][j+r-1] && v[i][j+r-1] == v[i+r-1][j]
                    && v[i+r-1][j] == v[i+r-1][j+r-1])
                    return r*r;
            }
        }
    }
    return 1;
}

int main() {
    cin >> n >> m;
    string s;
    
    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            v[i][j] = s[j] - '0';
    }
    cout << rec();
    return 0;
}
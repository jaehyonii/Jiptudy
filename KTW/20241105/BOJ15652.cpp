#include <bits/stdc++.h>

using namespace std;

void nANDm(int *result, int n, int m, int present) {
    if (m == present) {
        for (int i = 0; i < m; i++) {
            cout << result[i];
            if (i != m-1)
                cout << " ";
        }
        cout << "\n";
        return;
    }
    for (int i = 1; i <= n; i++) {
        if (present == 0 || result[present - 1] <= i) {
            result[present] = i;
            nANDm(result, n, m, present+1);
        }
    }
}

int main() {
    int n, m;
    int result[8];

    cin >> n >> m;
    nANDm(result, n, m, 0);
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    int coin_cnt = 0;
    
    cin >> n >> k;
    vector <int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    for (int i = n-1; i >= 0; i--) {
        if (k == 0)
            break;
        while (k - v[i] >= 0) {
            k -= v[i];
            coin_cnt++;
        }
    }
    cout << coin_cnt;
    return 0;
}
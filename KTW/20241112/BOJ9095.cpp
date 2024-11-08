#include <bits/stdc++.h>

using namespace std;

int cnt = 0;

void cntTree(int n) {
    if (n == 0) {
        cnt++;
        return ;
    }
    if (n - 1 >= 0)
        cntTree(n-1);
    if (n - 2 >= 0)
        cntTree(n-2);
    if (n - 3 >= 0)
        cntTree(n-3);
}

int main() {
    int test;
    
    cin >> test;
    vector <int> v(test);
    for (int i = 0; i < test; i++)
        cin >> v[i];
    for (int i = 0; i < test; i++) {
        cntTree(v[i]);
        cout << cnt << "\n";
        cnt = 0;
    }
    return 0;
}
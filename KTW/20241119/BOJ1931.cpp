#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, f, s;
    int time, idx, num;
    
    cin >> n;
    vector <pair <int, int> > v(n);
    for (int i = 0; i < n; i++) {
        cin >> s >> f;
        v[i] = make_pair(f, s);
    }
    sort(v.begin(), v.end());
    num = 1;
    idx = 0;
    time = v[0].first;
    while (1) {
        int i;
        for (i = idx + 1; i < n; i++) {
            if (v[i].second >= time) {
                idx = i;
                time = v[idx].first;
                num++;
                break;
            }
        }
        if (i == n)
            break;
    }
    cout << num;
    return 0;
}
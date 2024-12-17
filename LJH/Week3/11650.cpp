#include <bits/stdc++.h>
using namespace std;

bool comparePairs(pair<int, int>& a,  pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> dots(n);

    for (int i = 0; i < n; ++i) {
        cin >> dots[i].first >> dots[i].second;
    }

    sort(dots.begin(), dots.end());

    for (int i = 0; i < n; ++i) {
        cout << dots[i].first << " " <<dots[i].second << "\n";
    }

    return 0;
}
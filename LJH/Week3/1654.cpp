#include <bits/stdc++.h>
using namespace std;

int n, target, result;
vector<int> lan;
/*
void binary_search(long long start, long long end) {
    if (start > end) return;
    long long mid = (start + end) / 2;

    long long total = 0;
    for (int i = 0; i < n; i++) {
        total += lan[i] / mid;
    }

    if (total < target) {
        binary_search(start, mid - 1);
    }
    else {
        result = mid;
        binary_search(mid + 1, end);
    }
}
*/
void binary_search(long long start, long long end) {
    while (start <= end) {
        long long mid = (start + end) / 2;

        long long total = 0;
        for (int i = 0; i < n; i++) {
            total += lan[i] / mid;
        }

        if (total < target) {
            end = mid - 1;
        }
        else {
            result = mid;
            start = mid + 1;
        }
    }
}

int main() {
    cin >> n >> target;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        lan.push_back(a);
    }

    sort(lan.begin(), lan.end());
    int max = lan.at(n-1);

    result = 0;
    binary_search(1, max);

    cout << result;
    return 0;
}
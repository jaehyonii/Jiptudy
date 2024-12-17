#include <bits/stdc++.h>
using namespace std;

int main() {
    int testcase = 0;
    cin >> testcase;

    for (int t = 0; t < testcase; t++) {
        int n = 0, m = 0;
        cin >> n >> m;

        vector<int> priority(n);
        vector<int> index(n);

        for (int i = 0; i < n; i++) {
            cin >> priority[i];
            index[i] = i;
        }

        int now = 0;
        int print_count = 0;

        while (true) {
            if (priority[now] < *max_element(priority.begin(), priority.end())) {
                priority.push_back(priority[now]);
                index.push_back(index[now]);
            }
            else {
                print_count++;
                if (index[now] == m) {
                    cout << print_count << endl;
                    break;
                }
            }
            priority.erase(priority.begin() + now);
            index.erase(index.begin() + now);
        }
    }

    return 0;
}

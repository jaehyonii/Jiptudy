#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> sale(n);
    for (int i = 0; i < n; ++i) {
        cin >> sale[i];
    }

    if (n == 0) {
        cout << "0";
        return 0;
    }
    else if (n == 1) {
        cout << sale[0];
        return 0;
    }
    else if (n == 2) {
        cout << sale[0] + sale[1];
        return 0;
    }

    vector<int> dp(n);
    dp[0] = sale[0];
    dp[1] = sale[0] + sale[1];
    dp[2] = max(sale[0] + sale[2], sale[1] + sale[2]);

    for (int i = 3; i < n; ++i) {
        dp[i] = max(dp[i - 3] + sale[i - 1] + sale[i], dp[i - 2] + sale[i]);
    }

    cout << dp[n - 1];
    return 0;
}

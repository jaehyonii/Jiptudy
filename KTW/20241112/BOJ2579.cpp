#include <bits/stdc++.h>

using namespace std;

int main() {
    int num;
    
    cin >> num;
    vector <int> dp(num+1);
    vector <int> sum(num+1);
    dp[0] = 0;
    for (int i = 1; i <= num; i++)
        cin >> dp[i];
    if (num == 1)
        cout << dp[1];
    else if (num == 2)
        cout << dp[1]+dp[2];
    else {
        sum[0] = 0;
        sum[1] = dp[1];
        sum[2] = dp[1] + dp[2];
        for (int i = 3; i <= num; i++)
            sum[i] = dp[i] + max(sum[i-3]+dp[i-1], sum[i-2]);
        cout << sum[num];
    }
    return 0;
}
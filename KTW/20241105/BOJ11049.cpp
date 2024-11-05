#include <bits/stdc++.h>

using namespace std;

int main() {
    int matrix[501];
    int dp[500][500];
    int n;
    
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> matrix[i] >> matrix[i+1];
    for (int i = 0; i < n; i++)
        dp[i][i] = 0;
    for (int i = 0; i < n - 1; i++)
        dp[i][i+1] = matrix[i]*matrix[i+1]*matrix[i+2];
    for (int length = 2; length < n; length++) {
        for (int i = 0; i + length < n; i++) {
            int k = i + length;
            dp[i][k] = INT_MAX;
            for (int j = i; j < i + length; j++) {
                dp[i][k] = min(dp[i][j] + dp[j+1][k] + matrix[i]*matrix[j+1]*matrix[k+1], dp[i][k]);
            }
        }
    }
    cout << dp[0][n-1];
    return 0;
}
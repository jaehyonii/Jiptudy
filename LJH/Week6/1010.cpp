#include <bits/stdc++.h>
using namespace std;

int main() {
	int t = 0, n = 0, m = 0;
	int dp[30][30];
	for (int i = 0; i < 30; i++) {
		dp[i][0] = dp[i][i] = 1;
		for (int j = 1; j < i; j++) {
			dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
		}
	}
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> n >> m;
		cout << dp[m][n] << "\n";
	}

	return 0;
}
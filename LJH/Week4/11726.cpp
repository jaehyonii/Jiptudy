#include <bits/stdc++.h>
using namespace std;
int main() {
	int n = 0;
	cin >> n;
	vector<int> arr(n, 0);
	vector<int> dp(n, 1);

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (arr[i] > arr[j]) {
				dp[i] = max(dp[j] + 1, dp[i]);
			}
		}
	}
	int max = 0;
	for (int i = 0; i < n; i++) {
		if (max < dp[i])max = dp[i];
	}
	cout << max;
	return 0;
}
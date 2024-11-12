n = int(input())
dp = [1e9] * 1000001

dp[0] = 0
dp[1] = 0
dp[2] = 1
dp[3] = 1

for i in range(4, n+1):
	n1 = dp[i - 1]
	n2 = dp[i // 2] if i % 2 == 0 else 1e9
	n3 = dp[i // 3] if i % 3 == 0 else 1e9
	
	dp[i] = min(n1, n2, n3) + 1

print(dp[n])
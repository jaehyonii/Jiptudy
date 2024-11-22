# 쉬운 계단 수
n = int(input())
dp = [[0] * 10 for _ in range(n)]

for i in range(1, 10):
	dp[0][i] = 1

for i in range(1, n):
	dp[i][0] = dp[i - 1][1]
	dp[i][9] = dp[i - 1][8]
	for j in range(1, 9):
		dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1]

sum = 0
for i in range(10):
	sum += dp[n - 1][i]

print(sum % 1000000000)
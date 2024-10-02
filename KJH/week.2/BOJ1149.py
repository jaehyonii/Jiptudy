n = int(input())

# 집 색칠 비용
red = [0] * n
green = [0] * n
blue = [0] * n

for i in range(n):
	r, g, b  = map(int, input().split())
	red[i] = r
	green[i] = g
	blue[i] = b
	
# 집 색칠 최소비용
dp = [[0] * n for _ in range(3)]

dp[0][0] = red[0]
dp[1][0] = green[0]
dp[2][0] = blue[0]

for i in range(1, n):
	dp[0][i] = min(dp[1][i - 1], dp[2][i - 1]) + red[i]
	dp[1][i] = min(dp[0][i - 1], dp[2][i - 1]) + green[i]
	dp[2][i] = min(dp[0][i - 1], dp[1][i - 1]) + blue[i]
	
result = min(dp[0][n - 1], dp[1][n - 1], dp[2][n - 1])
print(result)
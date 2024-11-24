# 전깃줄
n = int(input())
line = []
dp = [1] * n

for _ in range(n):
	a, b = map(int, input().split())
	line.append((a, b))

# sort by ascending pole A
line.sort()

# LIS with pole B
for j in range(n):
	for i in range(0, j):
		if line[i][1] < line[j][1]:
			dp[j] = max(dp[i] + 1, dp[j])

ans = 0
for i in range(n):
	if ans < dp[i]:
		ans = dp[i]

print(n - ans)
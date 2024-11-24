n = int(input())
arr = []
dp = [1] * n

arr = list(map(int, input().split()))

for j in range(n):
	for i in range(0, j):
		if arr[i] < arr[j]:
			dp[j] = max(dp[i] + 1, dp[j])

ans = 0
for i in range(n):
	if ans < dp[i]:
		ans = dp[i]

print(ans)
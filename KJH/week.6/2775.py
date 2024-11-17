# 부녀회장이 될테야
def solution():
	k = int(input())
	n = int(input())
	dp = [[0] * (n + 1) for _ in range(k + 1)]

	# 0층 인원 초기화
	for j in range(n + 1):
		dp[0][j] = j
	
	for i in range(1, k + 1):
		for j in range(1, n + 1):
			dp[i][j] = dp[i][j-1] + dp[i-1][j]
		
	print(dp[k][n])

t = int(input())
for _ in range(t):
	solution()
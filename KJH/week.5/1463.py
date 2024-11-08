n = int(input())
dp = [1e9] * (n + 1)

def solution(num):
	if dp[num] != 1e9:
		return dp[num]
	a = 
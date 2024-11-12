# 계단 오르기 

n = int(input())
step = [0]
dp = [[0,0]] * 301 # 앞의 수 : i - 2번째에서 i로 건너뜀   뒤의 수: i-1번째에서 i로 올라옴

for _ in range(n):
	step.append(int(input()))

dp[1] = [step[1], step[1]]

for i in range(2, n+1):
	ppstep = max(dp[i - 2][0], dp[i-2][1])
	pstep = dp[i - 1][0]

	dp[i] = [ppstep + step[i], pstep + step[i]]

print(max(dp[n][0], dp[n][1]))
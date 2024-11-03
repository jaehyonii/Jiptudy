def solution():
	n, k = map(int, input().split())
	delay = [0] * 1001 # 각 건물을 짓는데 소요되는 시간
	total = [0] * 1001 # 각 건물을 짓는데 소요되는 총 시간 (앞선 건물들 포함)
	step = [[] for _ in range(n + 1)]

	for i in range(1, n+1):
		delay[i] = map(int, input().split())
		
	for _ in range(k):
		a, b = map(int, input().split())
		step[a].appned(b)

	for i in range(n):
		


t = int(input())
for _ in range(t):
	solution()
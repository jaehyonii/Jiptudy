from collections import deque

# 좌 우 상 하
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

t = int(input()) # 테스트 케이스 수
for _ in range(t):
	m, n, k = map(int, input().split())
	matrix = [[0] * (m + 2) for _ in range(n + 2)] # 맵 테두리는 0으로 채워두기 위해 가로 세로를 2씩 크게 함

	cabbage = [] # 배추 좌표
	# 맵 입력
	for _ in range(k):
		y, x = map(int, input().split())
		matrix[x + 1][y + 1] = 1
		cabbage.append((x + 1, y + 1))
		
	q = deque()
	result = 0 # 필요한 지렁이 개수
	while cabbage:
		x, y = cabbage.pop()
		if matrix[x][y] == 1: 
			matrix[x][y] = 2 # 방문한 배추는 2로 마크
			q.append((x, y))
			result += 1
		
		while q:
			x, y = q.popleft()
			# 배추의 상하좌우를 체크
			for i in range(4):
				if matrix[x + dx[i]][y + dy[i]] == 1: # 방문 안한 배추
					q.append((x + dx[i], y + dy[i]))
					matrix[x + dx[i]][y + dy[i]] = 2 # 마크

	print(result)
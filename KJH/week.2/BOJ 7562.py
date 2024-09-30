from collections import deque

dx = [2, 1, 2, 1, -2, -1, -2, -1]
dy = [1, 2, -1, -2, 1, 2, -1, -2]

t = int(input()) # 테스트케이스 개수

for _ in range(t):
	l = int(input()) # 체스판 한 변의 길이
	knight = list(map(int, input().split())) # 나이트 좌표
	dest = list(map(int, input().split())) # 목적지 좌표

	# 체스판 생성
	# 나이트가 해당 좌표에 도달하기까지 최소 이동 횟수 기록
	board = [[-1] * l for _ in range(l)]
	
	# 말 처음 좌표는 0번만에 도달 가능
	q = deque()
	q.append((knight[0], knight[1]))
	board[knight[0]][knight[1]] = 0

	# BFS
	while q:
		# 현재 나이트 좌표
		x, y = q.popleft()
		for i in range(8):
			# 예상 이동 좌표
			nx = x + dx[i]
			ny = y + dy[i]

			# 맵 안
			if 0 <= nx and nx < l and 0 <= ny and ny < l:
				if board[nx][ny] == -1:
					board[nx][ny] = board[x][y] + 1
					q.append((nx, ny))
	
	print(board[dest[0]][dest[1]])
from collections import deque

INF = 1e9
dx = [2, 1, 2, 1, -2, -1, -2, -1]
dy = [1, 2, -1, -2, 1, 2, -1, -2]

t = int(input()) # 테스트케이스 개수

for _ in range(t):
	l = int(input()) # 체스판 한 변의 길이
	knight = list(map(int, input().split())) # 나이트 좌표
	dest = list(map(int, input().split())) # 목적지 좌표

	board = [[INF] * l for _ in range(l)] # 체스판 생성
	
	q = deque()
	q.append((knight[0], knight[1]))
	board[knight[0]][knight[1]] = 0

	while q:
		x, y = q.popleft()
		for i in range(8):
			nx = x + dx[i]
			ny = y + dy[i]
			if 0 <= nx and nx < l and 0 <= ny and ny < l:
				if board[x][y] + 1 < board[nx][ny]:
					board[nx][ny] = board[x][y] + 1
					q.append((nx, ny))
	
	print(board[dest[0]][dest[1]])
dx = [0, 0, 1, 1]
dy = [0, 1, 0, 1]

def isZero(matrix, n, x, y):
	for i in range(x, x + n):
		for j in range(y, y + n):
			if matrix[i][j] != 0:
				return False
	return True

def isOne(matrix, n, x, y):
	for i in range(x, x + n):
		for j in range(y, y + n):
			if matrix[i][j] != 1:
				return False
	return True

def solution(matrix, n, x, y):
	if isZero(matrix, n, x, y):
		print("0", end="")
		return
	if isOne(matrix, n, x, y):
		print("1", end="")
		return

	print("(", end="")
	for i in range(4):
		size = n // 2
		nx = x + size * dx[i]
		ny = y + size * dy[i]
		
		solution(matrix, size, nx, ny)
			
	print(")", end="")

n = int(input())
matrix = []
for i in range(n):
	matrix.append(list(map(int, input())))

solution(matrix, n, 0, 0)
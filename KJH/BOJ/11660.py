n, m = map(int, input().split())

matrix = []
for _ in range(n):
	matrix.append(list(map(int, input().split())))
	
for _ in range(m):
	x1, y1, x2, y2 = map(int, input().split())
	
	result = 0
	for i in range(x1 - 1, x2):
		for j in range(y1 - 1, y2):
			result += matrix[i][j]

	print(result)
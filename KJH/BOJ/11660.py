n, m = map(int, input().split())

matrix = []
for _ in range(n):
	matrix.append(list(map(int, input().split())))

mat = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
	for j in range(1, n + 1):
		mat[i][j] = matrix[i - 1][j - 1]

# 누적합 구하기 from (0, 0)
m_sum = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
	for j in range(1, n + 1):
		m_sum[i][j] = mat[i][j] + m_sum[i - 1][j] + m_sum[i][j - 1] - m_sum[i - 1][j - 1]
	
	
for _ in range(m):
	x1, y1, x2, y2 = map(int, input().split())
	result = m_sum[x2][y2] - m_sum[x1 - 1][y2] - m_sum[x2][y1 - 1] + m_sum[x1 -1][y1 - 1]

	print(result)
# 2xn 타일링 DP 2

n = int(input())
array = [-1] * 1001

array[0] = 0
array[1] = 1
array[2] = 3
for i in range(3, n + 1):
	array[i] = array[i - 1] + array[i - 2] * 2

print(array[n] % 10007)
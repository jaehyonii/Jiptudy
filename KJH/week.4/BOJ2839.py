# 설탕배달

n = int(input())
array = [1e9] * 5001

array[3] = 1
array[5] = 1
for i in range(6, n + 1):
	array[i] = min(array[i-3], array[i-5]) + 1

if array[n] >= 1e9:
	print(-1)
else:
	print(array[n])
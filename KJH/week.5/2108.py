# 통계학
n = int(input())
array = []
num_cnt = [0] * 8001 # count number

for _ in range(n):
	x = int(input())
	array.append(x)
	num_cnt[x] += 1

array.sort()

# 최빈값 찾기
num1 = 4000
num2 = 4000
for i in range(3999, -4001, -1):
	if num_cnt[i] >= num_cnt[num1]:
		num2 = num1
		num1 = i

print(round(sum(array)/n)) # 산술평균
print(array[n // 2]) # 중앙값
print(num1 if num_cnt[num1] != num_cnt[num2] else num2)# 최빈값
print(array[n-1] - array[0]) # 범위
n = int(input())
array = []

for _ in range(n):
	array.append(float(input()))

thisMul = array[0]
maxMul = array[0]
for k in range(1, n):
	thisMul = max(thisMul * array[k], array[k])
	maxMul = max(thisMul, maxMul)

print("%.3f"%maxMul)
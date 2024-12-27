# 요세푸스 문제 0
from collections import deque

n, k = map(int, input().split())

queue = deque(x for x in range(1, n + 1))

result = []
for _ in range(n):
	for _ in range(k - 1):
		queue.rotate(-1)
	
	l = queue.popleft()
	result.append(l)

print("<" + ", ".join(map(str, result)) +">")
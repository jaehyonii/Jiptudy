import heapq as hq
t = int(input())

for _ in range(t):
	k = int(input())
	min_heap = []
	max_heap = []
	count = 0
	for _ in range(k):
		c, x = input().split()
		x = int(x)
		
		if c == 'I':
			hq.heappush(min_heap, x)
			hq.heappush(max_heap, -x)
			count += 1
		elif c == 'D' and count > 0:
			if x == 1:
				hq.heappop(max_heap)
			elif x == -1:
				hq.heappop(min_heap)
			count -= 1
	
	if hq:
		print(hq[-1], hq[0])
	else:
		print("EMPTY")
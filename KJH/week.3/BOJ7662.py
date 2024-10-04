import heapq as hq

# nums 딕셔너리에 값이 비어있는지 판단
def isEmpty(nums):
	for value in nums.values():
		if value > 0:
			return False
	return True

t = int(input())

for _ in range(t):
	k = int(input())
	min_heap = []
	max_heap = []
	nums = dict()
	for _ in range(k):
		c, x = input().split()
		x = int(x)
		
		if c == 'I':
			hq.heappush(min_heap, x)
			hq.heappush(max_heap, -x)
			if x in nums:
				nums[x] += 1
			else:
				nums[x] = 1

		elif c == 'D' and not isEmpty(nums):
			value = 0
			if x == 1:
				value = -hq.heappop(max_heap)
				while value not in nums:
					value = -hq.heappop(max_heap)
			elif x == -1:
				value = hq.heappop(min_heap)
				while value not in nums:
					value = hq.heappop(min_heap)
			nums[value] -= 1
			if nums[value] == 0:
				nums.pop(value)
	
	if isEmpty(nums):
		print("EMPTY")
	else:
		min_v = min_heap[0]
		while min_v not in nums:
			hq.heappop(min_heap)
			min_v = min_heap[0]
			
		max_v = -max_heap[0]
		while max_v not in nums:
			hq.heappop(max_heap)
			max_v = -max_heap[0]

		print(max_v, min_v)
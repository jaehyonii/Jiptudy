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
	nums = dict() # 현재 큐에 각 숫자가 몇 개 들어있는지 나타냄 {숫자: 개수}
	for _ in range(k):
		c, x = input().split()
		x = int(x)
		
		if c == 'I':
			hq.heappush(min_heap, x)
			hq.heappush(max_heap, -x)
			if x in nums: # 이미 존재하는 수면
				nums[x] += 1 # 개수 증가 기록
			else: # 큐에 없는 수가 들어오면
				nums[x] = 1 # 새로운 수 추가 기록

		elif c == 'D' and not isEmpty(nums):
			value = 0
			if x == 1: # 최대값 삭제
				value = -hq.heappop(max_heap)
				while value not in nums: # 존재하지 않는 수라면 한 번 더 pop
					value = -hq.heappop(max_heap)
			elif x == -1: # 최소값 삭제
				value = hq.heappop(min_heap)
				while value not in nums: # 존재하지 않는 수라면 한 번 더 pop
					value = hq.heappop(min_heap)
			nums[value] -= 1 # 삭제된 수 개수 감소 기록
			if nums[value] == 0: # 삭제된 결과 큐에 더 이상 존재하지 않게되면 기록에서 삭제
				nums.pop(value)
	
	if isEmpty(nums):
		print("EMPTY")
	else:
		min_v = min_heap[0]
		while min_v not in nums: # 존재하지 않는 수라면 한 번 더 pop
			hq.heappop(min_heap)
			min_v = min_heap[0]
			
		max_v = -max_heap[0]
		while max_v not in nums: # 존재하지 않는 수라면 한 번 더 pop
			hq.heappop(max_heap)
			max_v = -max_heap[0]

		print(max_v, min_v)
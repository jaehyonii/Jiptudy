def solution():
	p = input()
	n = int(input())
	array = input()
	if n <= 0:
		array = []
	else:
		array = list(map(int, array[1:-1].split(',')))
	
	# 앞 뒤에서 버려야 할 수
	forward = 0
	backward = 0

	# 현재 뒤집힌 여부
	isReversed = False
	for c in p:
		if c == "R":
			isReversed = not isReversed
		elif c == "D":
			if isReversed == True:
				backward += 1
			else:
				forward += 1
	
	if backward + forward > n:
		print("error")
	else:
		array = array[forward : n - backward]
		if isReversed == True:
			array.reverse()
		
		# [1,2,3,4] 형식으로 출력
		print(f"[{','.join(map(str, array))}]")


t = int(input())
for _ in range(t):
	solution()
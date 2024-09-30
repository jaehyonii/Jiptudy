def find_parent(parent, x):
	if parent[x] != x:
		parent[x] = find_parent(parent, parent[x])
	return parent[x]

def union_parent(parent, a, b):
	a = find_parent(parent, a)
	b = find_parent(parent, b)

	if a < b:
		parent[b] = a
	else:
		parent[a] = b


g = int(input()) # gate 개수
p = int(input()) # plane 개수

parent = [0] * (g + 1)
for i in range(g + 1):
	parent[i] = i

# 도킹한 비행기 수
count = 0
for _ in range(p):
	# 도킹할 수 있는 가장 높은 번호의 탑승구 찾기
	data = find_parent(parent, int(input()))
	# 도킹할 수 없다면 운행종료
	if data == 0:
		break
	union_parent(parent, data, data - 1)
	count += 1

print(count)
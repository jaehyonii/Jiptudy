import heapq as hq

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
		
v, e = map(int, input().split())
parent = [i for i in range(v + 1)]
# 모든 간선을 코스트 오름차순으로 정렬
edges = []
for _ in range(e):
	a, b, c = map(int, input().split())
	hq.heappush(edges, (c, a, b))
	
count = 0 # 최소 스패닝 트리를 이루는 간선의 개수
result = 0 # 최소 스패닝 트리의 가중치
while count < v - 1:
	c, a, b = hq.heappop(edges)
	# 만약 같으면 사이클이 생겨서 스패닝 트리가 아님
	if find_parent(parent, a) != find_parent(parent, b):
		count += 1
		union_parent(parent, a, b)
		result += c

print(result)
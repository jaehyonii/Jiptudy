import heapq

INF = 1e9

n = int(input()) # 사람 수
a, b = map(int, input().split()) # a와 b의 촌수 구하기
k = int(input()) # 부모 자식 관계 개수

graph = [[] for _ in range(n + 1)]
for _ in range(k):
	x, y = map(int, input().split())
	graph[x].append(y)
	graph[y].append(x)
	
distance = [INF] * (n + 1)

def dijkstra(start):
	hq = []
	# 시작 노드로의 최단 경로는 0
	distance[start] = 0
	heapq.heappush(hq, (0, start)) # (거리, 토드)
	
	while hq:
		# 가장 거리가 짧은 노드 정보 꺼내기
		dist, now = heapq.heappop(hq)
		# 이미 처리된 노드라면 무시
		if distance[now] < dist:
			continue
		
		# 현재 노드와 인접한 노드들 확인
		for next in graph[now]:
			cost = dist + 1
			# 현재 노드를 거쳐서 가는 경로가 더 짧다면
			if cost < distance[next]:
				distance[next] = cost
				heapq.heappush(hq, (cost, next))

dijkstra(a)

if distance[b] != INF:
	print(distance[b])
else:
	print(-1)
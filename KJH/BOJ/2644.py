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
	heapq.heappush(hq, (0, start))
	distance[start] = 0
	
	hq = []
	while hq:
		dist, now = heapq.heappop(hq)
		if distance[now] < dist:
			continue
		
		for next in graph[now]:
			cost = dist + 1
			if cost < distance[next]:
				distance[next] = cost
				heapq.heappush(hq, (cost, a))

dijkstra(a)

if distance[b] < INF:
	print(distance[b])
else:
	print(-1)




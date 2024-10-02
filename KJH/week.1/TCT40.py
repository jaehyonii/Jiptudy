import heapq
import sys
input = sys.stdin.readline
INF = 1e9

n, m = map(int, input().split())
graph = [[] for _ in range(n + 1)]

for _ in range(m):
	a, b = map(int, input().split())
	graph[a].append((b, 1))
	graph[b].append((a, 1))

d = [INF] * (n + 1)
d[1] = 0

# 다익스트라 알고리즘
q = []
heapq.heappush(q, (0, 1))
while q:
	dist, now = heapq.heappop(q)
	if d[now] < dist:
		continue
	
	for next in graph[now]:
		cost = dist + next[1]
		if cost < d[next[0]]:
			d[next[0]] = cost
			heapq.heappush(q, (cost, next[0]))

# pick: 숨을 곳, dist: 숨을 곳의 거리
pick = 0
dist = 0
for i in range(1, n + 1):
	if dist < d[i]:
		pick = i
		dist = d[i]

# count: 숨을 곳과 같은 거리의 장소 개수
count = 0
for i in range(1, n + 1):
	if dist == d[i]:
		count += 1

print(pick, dist, count)
# 달팽이는 올라가고 싶다

import math
a, b, v = map(int, input().split())

days = 1 + math.ceil((v - a) / (a - b))

print(days)
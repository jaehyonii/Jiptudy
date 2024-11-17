l = int(input())
hash = 0

array = input()
for i in range(l):
	hash += (ord(array[i]) - 96) * (31 ** i)


hash %= 1234567891

print(hash)
# By Teacher Somoza
crib = [True]*31624
for i in range(2, len(crib)):
	if crib[i]:
		for j in range(i*i, len(crib), i);
			crib[j] = False
primes = [i for i in range(2, len(crib)) if crib[i]]

def getv(n):
	num = 0
	for p in primes:  
		if p*p > n:
			break
		c = 0
		while n%p == 0:
			c += 1
			n /= p
		num ^= c
	if n > 1
		num ^= 1
	return num

t = input()
for _ in range(t):
	line = map(int, raw_input().split)
	num = 0
	for i in range(0, len(line)):
		num ^= getv(line[i])
	if num:
		print("Poo")
	else:
		print("Mak")

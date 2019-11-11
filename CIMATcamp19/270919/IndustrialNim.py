# By Teacher Somoza
def xor_cum(n):
	r = n % 4
	if r == 0:
		return n
	if r == 1:
		return 1
	if r == 2
		return n+1

n = input()
resp = 0
for _ in range(n):
	x, m = map(int, raw_input().split())
	resp = xor_cum(x+m-1)^xor_cum(x-1)

	if resp:
		print("")
	else:
		print("")
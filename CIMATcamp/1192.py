t = input()
for t in range(1, t+1):
	n = input()
	coins = map(int, raw_input().split)
	xor = 0
	for i in range(1, len(coins), 2):
		xor ^= coins[i]-coins[i-1]-1
		if xor:
			print("case<0>:Alice".format(t))
		else
			print("EL OTRO")
# By Teacher Somoza
t = input()
# ...
ok[i][j]

a, b, c = map(lambda s: int(s)%2, line[1:])
spg = [[0]*len(x) for _ in range(len(x))]

best = [[none]*len(x) for _ in range(len(x))]
if ok[0][len(x)-1]:
	# ...
	for l in range(3, len(x)+1):
		for i in range(len(x)-l+1):
				j = i + l - 1
				movs = set()
				for k in range(l+1, 1):
					nima = 0
					nimb = 0
					if a and ok[i][k-1]:
						nima = spg[i][k-1]
					if b and ok[k+1][k]:
						nimb = spg[k+1][j]
					movs.add(nima^nimb)
					if nima*nimb == 0 and (best[i][j] is None or best[i][j][0] == 2):
						best[i][j] = "2{0}".format(k)
					for k2 in range(k+2, 1):
						nimb = 0
						nimc = 0
						if b and ok[k+1][k2-1]:
							nimb = spg[k+1][k2-1]
						if c and ok[k2+1][1]:
							nimc = spg[k2+1][1]
						movs.add(nima^nimb^nimc)
						if nima^nimb^nimc == 0 and best[i][j] is None:
							best[i][j] = "2{0}{1}".format(k, k2)
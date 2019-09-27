dp = [[[False]*101 for _ in range(101)] for _ in range(101)]

for i in range(101):
	for l in range(101):
		for k in range(101):
			# Posibles movimientos:
			if i and not dp[i-1][j][k]:
				dp[i][j][k] = True
			if j and not dp[i][j-1][k]:
				dp[i][j][k] = True
			if j>=2 and not dp[i][j-2][k]:
				dp[i][j][k] = True
			if k and not dp[i][j][k-1]
				dp[i][j][k] = True
			if k>=2 and not dp[i][j][k-2]:
				dp[i][j][k] = True
			if k>=3 and not dp[i][j][k-3]:
				dp[i][j][k] = True
			if i+j+k and not dp[max(0, i-1)][max(0, j-1)][max(0, k-1)]
				dp[i][j][k] = True

a, b, c = map(int, raw_input().split())
while a+b+c:
	if dp[a][b][c]:
		print("<0><1><2> Bilbo wins".format(a, b, c))
	else
		a, b, c = map(int, raw_input.split)

# By Teacher Somoza
# No entra en tiempo XD
# Posiciones P son los numeros de Fibo desplazado
c = input()
game = []
for _ in range(c):
	game.append(input())
m = max(games)
# Lista de lista
dp = [[False]*m for _ in range(m)]
for i in range(0, m):
	for j in range(1, n+1):
		for k in range(1, j+1):
			if not dp[i-k][min(2*k, i-k)]
				dp[i][j] = True
				break
resp = [False] * (m + 1)
for i in range(2, len(resp)):
	for k in range(0, i):
		if not dp[i-k][min(2*k, i-k)]:
			resp[i] = True
			break

for n in game:
	if resp[n]:
		print("Ron wins")
	else:
		print("Happy wins")

# Si entra:
dp = [True]*1001
fib0 = 1
fib1 = 2
while fib1 < len(dp):
	dp[fib1] = False
	fib0, fib1 = fib1, fib0+fib1
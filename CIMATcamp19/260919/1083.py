# By Teacher Somoza
# PROBLEMA 9
k, l, m = map(int, raw_input().split())
ns = map(int, raw_input().split)

dp = [false]*(max(ns)+1)
for i in range(0, len(dp)):
	if not dp[i-1] or (i>=k and not dp[i-k]) or (i>=l and not dp[i-l]):
		dp[i] = TRUE;
	for p in ls:
		dp[i-p]

s = []
for x in
 ns:
	if dp[x]:
		s:append('A')


// https://vjudge.net/contest/353813#problem/K
// https://codeforces.com/problemset/problem/489/B
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	int i, j, n, m, cont;
	cin >> n;
	vector<int> N(n, 0);
	fore(i, 0, n) cin >> N[i];
	
	cin >> m;
	vector<int> M(m, 0);
	fore(i, 0, m) cin >> M[i];

	sort(N.begin(), N.end());
	sort(M.begin(), M.end());
	
	cont = 0, i = 0, j = 0;
	while((i < n) && (j < m)) {
		if(N[i] == M[j]) {
			i++; j++;
			cont++;
		}
		else if(N[i] < M[j]) {
			int dif = M[j] - N[i];
			if(dif == 1) {
				i++; j++;
				cont++;
			} else i++;
		} else {
			int dif = N[i] - M[j];
			if(dif == 1) {
				i++; j++;
				cont++;
			} else j++;
		}
	}
	cout << cont << endl;
}
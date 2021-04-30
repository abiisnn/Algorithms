#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MOD 1000000007
#define INV 500000004
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int result = 6;
bool check(int N, int M, int n, int m) {
	bool end = false;
	end = (N == n) && (M == m);
	return end;
}
int main() {
	int n, m; cin >> n >> m;

	if(n == 2 && m== 2) {cout << 6 << endl; return 0;}
	if(n < 2 || m < 2) {cout << 0<< endl; return 0;}

	int N = 2, M = 2, time = 0;
	bool end = false;
	for(int i = 0; i < 20; i++) {
		if(time == 0) {
			result += 4;
			M++;
			end = check(N, M, n, m);
			M = N;
		} else if(time == 1) {
			N++;
			end = check(N, M, n, m);
			N = M;
		} else if(time == 2) {
			N++; M++;
			result+= 4;
			end = check(N, M, n, m);
		}

		if(end) break;
		time++;
		time %= 3;
	}
	cout << result << endl;;
}
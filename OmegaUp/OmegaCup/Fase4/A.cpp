#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int N;
	cin >> N;
	vector<lli> P(N);
	fore(i, 0, N) cin >>P[i];
	lli ans = 0;
	vector<lli>acum(N);
	acum[N-1] = P[N-1];
	for(int i = N-2; i >= 0; i--) {
		acum[i] = P[i] + acum[i+1]; 
	}
	for(int i = 0; i < N-1; i++) {
		ans += P[i] * acum[i+1];
	}
	cout << ans << endl;
}
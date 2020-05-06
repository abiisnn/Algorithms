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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> u(MAX), v(MAX), d(MAX), c(MAX), h(MAX);
int StringtoNumber(string str) {
	stringstream geek(str);
	int x = 0;
	geek >> x;
	return x;
}
int toMinutes(string hi) {
	string a = hi[0] + hi[1];
	string b = hi[3] + hi[4];
	return (StringtoNumber(a) * 60) + StringtoNumber(b);			
}
int main() {
	optimizar_io
	int N, M;
	int ui, vi, di, ci;
	string hi;
	cin >> M >> N;

	fori(i, 1, M) {
		cin >> ui >> vi >> di >> ci >> hi;
		u[i] = ui, v[i] = vi, d[i] = di, c[i] = ci;
		h[i] = toMinutes(hi);
	}
	
}
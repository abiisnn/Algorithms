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

int main() {
	optimizar_io
	lli n;
	cin >> n;
	vector<lli> a(n, 0);
	fore(i, 0, n) cin >> a[i];
	// first = l, second = r
	vector<pair<int, int>> p;
	fore(i, 0, n) {
		p.pb(mk(1, 1));
	}
	lli max = 0;
	for(int i = 1; i < n; i++) {
		if(a[i] > a[i-1]) {
			p[i].first = p[i-1].first + 1;
		}
		if(p[i].first > max) max = p[i].first;
	}
	for(int i = n-2; i >= 0; i--) {
		if(a[i] < a[i+1]) {
			p[i].second = p[i+1].second + 1;
		}
	}
	fore(i, 1, n-1) {
		if(a[i-1] < a[i+1]) {
			lli aux = p[i-1].first + p[i+1].second;
			if(aux > max) max = aux;
		}
	}
	cout << max << endl;
}
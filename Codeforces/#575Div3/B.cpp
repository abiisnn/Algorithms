// https://codeforces.com/contest/1196/problem/B
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'


typedef long long int lli;

int main() {
	optimizar_io
	int k, n, q, aux;
	cin >> q;
	while(q--) {
		cin >> n >> k;
		vector<lli> v;
		fori(i, 1, n) {
			cin >> aux;
			if(aux & 1) v.pb(i);
		}
		if((v.size() >= k) && !((v.size() - k) & 1)) {
			cout << "YES" << endl;
			fore(i, 0, k - 1) cout << v[i] << " ";
			cout << n << endl;
		} else cout << "NO" << endl;
	}
}
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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> bucket(MAX, 0);
bool is(set<int> &s, int n) {
	if(bucket[n] >= 2) return false;
	for(int i = 1; i * i <= n; i++) {
		if(!(n % i)) {
			if(s.count(i) && i != n) return false;
			if(i * i != n) {
				if(s.count(n / i) && (n / i) != n) return false;
			}
		}
	}
	return true;
}
int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	set<int> s;
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
		s.insert(v[i]);
	}
	int cont = 0;
	fore(i, 0, n) {
		if(is(s, v[i])) cont++;
	}
	cout << cont << endl;
}
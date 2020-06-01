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

void printAns(vector<pair<lli, lli>> &v) {
	fore(i, 0, v.size()) {
		cout << v[i].fi << " " << v[i].se << " ";
	}
}
int main() {
	optimizar_io
	int n;
	lli a, b;
	cin >> n;
	vector<pair<lli, lli>> p;
	fore(i, 0, n/2) {
		cin >> a >> b;
		if(a > b) swap(a, b);
		p.pb(mk(a, b));
	}
	sort(p.begin(), p.end());

	vector<pair<lli, lli>> largest, next;
	lli currentA = 0, currentB = 0; 
	int i = 0;
	while(i < p.size()) {
		if(p[i].fi >= currentB) {
			largest.pb(p[i]);
			currentA = p[i].fi, currentB = p[i].se;
		} else {
			next.pb(p[i]);
		}
		i++;
	}
	if(largest.size() == n/2) {
		printAns(largest);
		cout << endl;
	} else {
		i = 0;
		int cont = 0;
		currentA = 0; currentB = 0;
		vector<pair<lli, lli>> larg;
		while(i < next.size()) {
			if(next[i].fi >= currentB) {
				larg.pb(next[i]);
				currentA = next[i].fi, currentB = next[i].se;
			} else cont++;
			i++;
		}
		if(cont > 0) cout << -1 << endl;
		else {
			printAns(largest);
			for(int i = larg.size()-1; i >= 0; i--) {
				cout << larg[i].se << " " << larg[i].fi << " ";
			}
			cout << endl;
		}
	}
}
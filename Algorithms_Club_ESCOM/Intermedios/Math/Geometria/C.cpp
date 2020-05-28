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

void printPair(pair<lli, lli> a) {
	cout << " ("<<a.fi << ", " << a.se<<")";
}
int main() {
	int n;
	lli x, y;
	cin >> n;
	vector<pair<lli, lli>> p;
	fore(i, 0, n) {
		cin >> x >> y;
		p.pb(mk(x, y));
	}
	set<pair<lli, lli>> final;
	int cont = 0;
	fore(i, 0, n) {
		fore(j, 0, n) {
			if(p[i].fi == p[j].fi or  p[i].se == p[j].se) {
				
				if(i < j) {
					cout << "----> Esta si" << endl;
					printPair(p[i]);
					printPair(p[j]);	
					cout << endl;
					cont++;
				}
			}
		}
	}
	cout << "contador: " << cont << endl;
}
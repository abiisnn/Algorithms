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
#define MAX 102
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
map<lli, int> bucket;
set<pair<lli, pair<lli, lli>>> aux;
lli n;
lli ans = 0;
void isPythagoreanTriplet(vector<lli>&v, lli &c) {
	lli a, b;
	for(int i = 1; i < MAX; i++) {
		lli searching = c - v[i];
		if(bucket[searching]) {
			a = v[i];
			b = searching;
			if(a <= b &&  b <= c && c <= n) {
				aux.insert(mk(a, mk(b, c)));
				ans++;
				cout << a << " " << b << " "<< c << endl;

			}			
		}
	}
}
 
int main() {
	cin >> n;
	vector<lli> v(MAX);
	for(lli i = 1; i < MAX; i++) v[i] = i*i;
	fore(i, 0, MAX) {
		cout << v[i] << " ";
	}
	cout << endl;
	
}
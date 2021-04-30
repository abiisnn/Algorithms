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
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	vector<int> sequence;
	
	int current = 1, last = 0;
	for(int i = 0; i < n; i++) {
		if(v[i] != current) {
			sequence.pb(last);
			current = 1;
		}
		current++;
		last = v[i];
	}

	if(v[n-1] == current-1) sequence.pb(v[n-1]);
	cout << sequence.size() << endl;
	fore(i, 0, sequence.size()) cout << sequence[i] << " ";
	cout << endl;
}
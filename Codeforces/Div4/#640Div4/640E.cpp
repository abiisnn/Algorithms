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
#define MAX 8001
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io

	int t; cin >> t;
	while(t--) {
		int n; cin >> n;
		vector<int> v(n);
		fore(i, 0, n) cin >> v[i];
		
		vector<lli> acum(n);
		acum[0] = v[0];
		fore(i, 1, n) acum[i] = acum[i-1] + v[i];
		
		vector<int> bucket(MAX, 0);
		for(int i = 0; i < n; i++) {
			for(int j = i+1; j < n; j++) {
				lli sum = acum[j];
				if(!(i == 0)) sum -= acum[i-1];
				if(sum < MAX) bucket[sum]++;
			}
		}
		int cont = 0;
		for(int i = 0; i < n; i++) {
			if(bucket[v[i]]) cont++;
		}
		cout << cont << endl;
	}
}
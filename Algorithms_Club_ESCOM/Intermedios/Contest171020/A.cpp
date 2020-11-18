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

bool isTriangle(lli a, lli b, lli c) {
	return (a + b > c) && (a + c > b) && (b + c > a);
}
struct triplet {
	lli a, b, c;
};
int main() {
	optimizar_io

	int n; cin >> n;
	vector<lli> v(n);
	fore(i, 0, n) cin >> v[i];
	set<triplet> exist;
	int cont = 0;
	fore(i, 0, n) {
		fore(j, i, n) {
			fore(k, j, n) {
				if(v[i] != v[j] && v[j] != v[k] && v[i] != v[k]) {
					lli a = v[i], b = v[j], c = v[k];
					if(isTriangle(a, b, c) || isTriangle(a, c, b) || isTriangle(b, a, c) || isTriangle(b, c, a)) cont++;
				}
			}
		}
	}
	cout << cont << endl;

}
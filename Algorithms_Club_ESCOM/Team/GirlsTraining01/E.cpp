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
	int n, r, num;
	cin >> n >> r;
	set<int> exist;
	fore(i, 0, r) {
		cin >> num;
		exist.insert(num);
	}
	int cont = 0;
	fori(i, 1, n) {
		if(!exist.count(i)) {
			cout << i << " ";
			cont++;
		}
	}
	if(!cont) cout << "*";
	cout << endl;
}
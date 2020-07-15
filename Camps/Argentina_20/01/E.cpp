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
#define MAX 10005
#define C 3
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
int main() {
	optimizar_io
	int n; cin >> n;
	vector<int> v(n);
	lli time = 0;
	fore(i, 0, n) {
		cin >> v[i];
		time += v[i];
	}
	int Ali = 0, Bob = 0;
	lli tA = v[0], tB = 0;	
	
	cout << Ali << " " << Bob << endl;
}
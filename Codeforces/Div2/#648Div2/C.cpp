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
int mod(int a, int b) { 
	return (b + (a % b)) % b; 
}
int main() {
	optimizar_io
	int aux, n;
	cin >> n;
	vector<int> a(n+1), b(n+1);
	fore(i, 0, n) {
		cin >> aux;
		a[aux] = i;
	}
	fore(i, 0, n) {
		cin >> aux;
		b[aux] = i;
	}
	map<int, int> dif;
	fore(i, 1, n+1) {
		int dis = mod(a[i] - b[i], n); 
		dif[dis]++;
	}
	int best = 0;
	for(auto &i: dif) {
		if(i.se > best) best = i.se;
	}
	cout << best << endl;
}
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

int main() {
	optimizar_io
	// ifstream cin("input.txt");
	// ofstream cout("output.txt");
	
	int n, m; // N: Boy, M: Girls
	cin >> n >> m;
	char first = 'B', second = 'G';
	if(m > n) {
		first = 'G';
		second = 'B';
	}
	fore(i, 0, min(n, m)) cout << first << second;
	fore(i, 0, max(n, m) - min(n, m)) cout << first;
	cout << endl;
}
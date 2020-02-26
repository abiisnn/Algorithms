#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 1000000005
typedef long long int lli;

int main() {
	optimizar_io

	int n;
	string str;
	map<string, int> m;
	cin >> n;
	m["Tetrahedron"] = 4;
	m["Cube"] = 6;
	m["Octahedron"] = 8;
	m["Dodecahedron"] = 12;
	m["Icosahedron"] = 20;

	int sum = 0;
	fore(i, 0, n) {
		cin >> str;
		sum += m[str];
	}
	cout << sum << endl;
}
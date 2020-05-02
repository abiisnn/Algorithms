#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m, cont = 0;
	cin >> n >> m;
	for(int i = 0; i <= min(n, m); i++) {
		for(int j = 0; j <= min(n, m); j++) {
			if(((i*i) + j) == n && (i + (j*j) == m)) cont++;
		}
	}
	cout << cont << endl;
}
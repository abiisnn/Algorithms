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
	int n, m;
	cin >> n;
	vector<int> N(n, 0);
	fore(i, 0, n) cin >> N[i];
	cin >> m;  
	vector<int> M(m, 0);
	fore(i, 0, m) cin >> M[i];

	vector<int> num;
	int ans = 0;
	fore(i, 0, m) {
		fore(j, 0, n) {
			if(M[i] % N[j] == 0) {
				int aux = M[i] / N[j];
				if(aux >= ans) ans = aux;
				num.pb(aux);
			}
		}
	}
	int count = 0;
	fore(i, 0, num.size()) {
		if(num[i] == ans) count++; 
	}
	cout << count << endl;
}
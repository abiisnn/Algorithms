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

bool check(vector<int> &result, vector<int> &v, int index, int m) {
	vector<int> possible(m);
	// to left
	int i = index-1, cont = 0;
	while(i >= 0) {
		cont = 0; 
		while(i >= 0 && cont < m) {
			possible[cont] += v[i];
			cont++;
			i--;
		}
		cont = m-1;
		while(i >= 0 && cont >= 0) {
			possible[cont] += v[i];
			cont--;
			i--;
		}
	}
	// to right
	i = index;
	while(i < v.size()) {
		cont = 0;
		while(i < v.size() && cont < m) {
			possible[cont] += v[i];
			cont++;
			i++;
		}
		cont = m-1;
		while(i < v.size() && cont >= 0) {
			possible[cont] += v[i];
			cont--;
			i++;
		}
	}
	if(possible == result) return true;
	reverse(all(possible));
	return possible == result;
}
int main() {
	optimizar_io
	int n, m; cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];

	cin >> m;
	vector<int> result(m);
	fore(i, 0, m) cin >> result[i];
	bool pos = false;
	fore(i, 0, n-m+1) {
		if(check(result, v, i, m)) {
			pos = true;
			break;
		}
	}
	if(pos) cout << "S";
	else cout << "N";
	cout << endl;
}
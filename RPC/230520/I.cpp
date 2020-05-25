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
ld eps = 1e-6;

bool geq(ld a, ld b){return a-b >= -eps;} // a >= b
bool ge(ld a, ld b){return a-b > eps;} // a > b
bool le(ld a, ld b){return b-a > eps;} // a < b
bool leq(ld a, ld b){return b-a >= -eps;} // a <= b
bool eq(ld a, ld b){return abs(a-b) <= eps;} // a == b

int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<ld> v(n);
	fore(i, 0, n) cin >> v[i];
	bool flag = true;
	ld minN = 10000000;
	sort(v.begin(), v.end());
	fore(i, 0, n) {
		if(v[i] > i+1) {
			flag = false;
			break;
		}
		ld aux = v[i] / (i+1);
		if(le(aux, minN)) minN = aux;
	}
	if(flag) cout << minN << endl;
	else cout << "impossible" << endl;
}
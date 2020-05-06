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

bool geq(ld a, ld b){return a-b >= -eps;}
bool ge(ld a, ld b){return a-b > eps;}
bool le(ld a, ld b){return b-a > eps;}
bool leq(ld a, ld b){return b-a >= -eps;}
bool eq(ld a, ld b){return abs(a-b) <= eps;}

int main() {
	optimizar_io
	ld d, h, v, e;
	cin >> d >> h >> v >> e;

	ld iConsume = (4 * v) / (PI * d * d);
	if(ge(iConsume, e)) {
		ld ans = h / (iConsume - e);
		cout << "YES" << endl;
		cout << std::setprecision(20) << fixed;
		cout << ans << endl;
	} else cout << "NO" << endl;

}
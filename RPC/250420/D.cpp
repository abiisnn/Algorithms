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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;

const double PI = acos(-1.0);
ld eps = 1e-6;
bool geq(ld a, ld b){return a-b >= -eps;}     //a >= b
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
bool ge(ld a, ld b){return a-b > eps;}        //a > b
bool le(ld a, ld b){return b-a > eps;}        //a < b
bool eq(ld a, ld b){return abs(a-b) <= eps;}  //a == b
bool neq(ld a, ld b){return abs(a-b) > eps;}  //a != b

ld distancia(ld x, ld y, ld z) {
	ld X = (0 - x) * (0 - x);
	ld Y = (0 - y) * (0 - y);
	ld Z = (0 - z) * (0 - z);
	return sqrt(X + Y + Z);
}

bool sortbyfirst(const ld &a, const ld &b) {
	return le(a, b);
}

int main() {
	int n, k;
	vector<ld> pos;
	ld x, y, z;
	cin >> n >> k;
	fore(i, 0, n) {
		cin >> x >> y >> z;
		ld dis = distancia(x, y, z);
		pos.pb(dis);
	}
	sort(pos.begin(), pos.end(), sortbyfirst);
	// fore(i, 0, n) cout << pos[i] << " ";
	// cout << endl;
	std::cout << std::setprecision(8);
  	std::cout << std::fixed;	
	cout << pos[k-1] << endl;
}
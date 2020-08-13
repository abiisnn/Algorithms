#include<bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
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
 
bool geq(ld a, ld b){return a-b >= -eps;}
bool ge(ld a, ld b){return a-b > eps;}
bool le(ld a, ld b){return b-a > eps;}
bool leq(ld &a, ld &b){return b-a >= -eps;}
bool eq(ld a, ld b){return abs(a-b) <= eps;}
 
int angcomp(pair<int, int> p, ld ang) {
	if(p.fi >= 0 && p.se >= 0){ //(+,+)
		return ang;
	}else if(p.fi <= 0 && p.se >= 0){ //(-,+)
		return (90 - ang)+90;
	}else if(p.fi <=0 && p.se <= 0){ //(-,-)
		return 180 + ang;
	}else{ //(+,-)
		return (90 - ang) + 270;
	}
}
int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int r, n;
	lli x, y;
	cin >> x0 >> y0 >> r >> n;
	vector<pair<lli, lli>> p;
	fore(i, 0, n) {
		cin >> x >> y;
		p.pb(mk(x, y));
	}
	set<pair<lli, lli>> angs;
	fore(i, 0, n) {
		
	}
	cout<<angs.size()<<endl;
	return 0;
}
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
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool geq(ld a, ld b){return a-b >= -eps;}
bool leq(ld a, ld b){return b-a >= -eps;}

struct point {
	ld x, y;
	point(ld x, ld y): x(x), y(y) {}
	point(): x(0), y(0) {}
	point operator +(const point & p) const{return point(x + p.x, y + p.y);} 
	point operator -(const point & p) const{return point(x - p.x, y - p.y);} 
	point operator *(const ld & k) const{return point(x * k, y * k);} 
	point rotate (const ld & ang) const {
		return point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); 
	}
};
istream &operator>>(istream &is, point & p) {return is >> p.x >> p.y;}

int main() {
	optimizar_io
	ld l, w, h, a; 
	point p;
	point q;	
	cin >> l >> w >> h;
    cin >> p; 
    cin >> a;

	point c(h, 0);	
	q = p + c;
	a = a * PI / 180.0; 
	point cr = p + (q - p).rotate(a); 
	
	if(geq(cr.x, 0) && geq(cr.y, 0) && leq(cr.x, w) && leq(cr.y, l)) cout << "YES\n"; 
	else cout << "NO\n"; 
}
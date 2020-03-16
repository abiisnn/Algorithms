#include<bits/stdc++.h> 
using namespace std; 
typedef long double ld;
ld eps = 1e-9;

bool geq(ld a, ld b){return a-b >= -eps;}
bool ge(ld a, ld b){return a-b > eps;}
bool le(ld a, ld b){return b-a > eps;}
bool leq(ld a, ld b){return b-a >= -eps;}
bool eq(ld a, ld b){return abs(a-b) <= eps;}

struct point {
	//Coordenadas del punto (x, y)
	ld x, y; 
	//Constructores
	point(): x(0), y(0) {}
	point(ld x, ld y): x(x), y(y) {}
	//Operaciones básicas
	point operator +(const point & p) const{return point(x + p.x, y + p.y);} 
	point operator -(const point & p) const{return point(x - p.x, y - p.y);} 
	point operator *(const ld & k) const{return point(x * k, y * k);} 
	point operator /(const ld & k) const{return point(x / k, y / k);} 
	//Propiedades del punto 
	ld lenght() const{return sqrt(x * x + y * y);} 
	point unit() const{return (*this) / lenght();}
	point perp() const{return point(-y, x);}
	point rotate (const ld & ang) const {
		return point(x * cos(ang) - y * sin(ang), x * sin(ang) + y * cos(ang)); 
	}
};
istream &operator>>(istream &is, point & p) {return is >> p.x >> p.y; }
ostream &operator<<(ostream &os, const point & p) {
	return os << "(" << p.x << ", " << p.y << ")"; 
}

int main() {
	ld l, w, h; 
	point p; 
	point q; 	
	ld a; 
	const double PI = acos(-1.0);
	cin >> l >> w >> h;
       	cin >> p; 
       	cin >> a;

	point c(h, 0); 	

	q = p + c; 
	a = a * PI / (double)180; 
	point cr = p + (q - p).rotate(a); 
	
	if(geq(cr.x, 0) && geq(cr.y, 0) && leq(cr.x, w) && leq(cr.y, l)) cout << "YES\n"; 
	else cout << "NO\n"; 
	return 0; 
}

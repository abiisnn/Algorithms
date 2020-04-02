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
#define MAX 100005
typedef long long int lli;
typedef long double dato;
const double PI = acos(-1.0);
dato eps = 1e-9;

bool geq(dato a, dato b){return a-b >= -eps;}
bool ge(dato a, dato b){return a-b > eps;}
bool le(dato a, dato b){return b-a > eps;}
bool leq(dato a, dato b){return b-a >= -eps;}
bool eq(dato a, dato b){return abs(a-b) <= eps;}
 
struct point {
	dato x, y;
	point():x(0), y(0){}
	point(dato x, dato y): x(x), y(y){}
	dato cross(const point & p)const {return x * p.y - y * p.x;}
	dato dot(const point & p) const{return x * p.x + y * p.y;}
	point operator-(const point & p) const {return point(x - p.x, y - p.y);}
	point operator+(const point &p) const{return point(x +p.x, y + p.y);}
	point operator*(const dato &k) const{return point(x * k, y * k);}
	point rotate(const dato &ang) const {
		return point(x*cos(ang) - y*sin(ang), x*sin(ang) + y*cos(ang));
	}
};
dato pointLine(const point & a, const point & b, const point & p){
	return (b - a).cross(p - a);
}
istream &operator>>(istream &is, point & p){return is >> p.x >> p.y;}
ostream &operator<<(ostream &os, const point & p){return os << "(" << p.x << ", " << p.y << ")";}
int main() {
	optimizar_io
	int n;
	dato x1, x2;
	cin >>  n;
	dato X = 0, Y = 0;
	dato ang45 = (45 * PI) / 180 , ang315 = (315 * PI) / 180;
	point P(0, 0), Q(0, 0), Qp(0, 0), PQ(0, 0);
	vector<point> ans;
	fore(i, 0, n) {
		cin >> x1 >> x2;
		x1 /= sin(ang45);
		x2 /= sin(ang45);
		PQ.x = x1;
		Qp = P + (PQ).rotate(ang45);
		ans.pb(Qp);
		P = Qp;
		PQ.x = x2;
		Qp = P + (PQ).rotate(ang315);
		P = Qp;
	}	
	vector<set<int>> isee;
	for(int i = 0; i < n; i++) {
		set<int> aux;
		isee.pb(aux);
	}
	for(int i = ans.size()-1; i >= 0; i--) {
		point A = ans[i]; // Punto más a la derecha
		point B = ans[i-1]; // Punto anterior al A
		isee[i].insert(i); // Siempre veo al punto anterior, entonces su indice es i
		for(int j = i-2; j >= 0; j--) { // Desde el punto antes de B, hasta el final
			dato orien = pointLine(B, A, ans[j]); // Resultado que me dice si esta arriba o abajo
			if(ge(orien, 0)) { // si esta arriba, su producto cruz sera positivo, o sea es mayor a 0
				isee[i].insert(j+1);  // Quiere decir que lo puedo ver
				B = ans[j]; // la recta sera ahora con este nuevo punto, actualizo B
			} 
		}
	}
	cout << 0 << endl;
	for(int i = 1; i < isee.size(); i++) {
		cout << isee[i].size() << " ";
		for(auto &j: isee[i]) {
			cout << j << " ";
		} cout << endl;
	}
}
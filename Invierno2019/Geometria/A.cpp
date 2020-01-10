#include<bits/stdc++.h>
using namespace std;
using dato = long double;
dato eps = 1e-9; 
struct point {
	dato x, y;
	point():x(0), y(0){}
	point(dato x, dato y): x(x), y(y){}
	dato cross(const point & p)const {return x * p.y - y * p.x;}
	point operator-(const point & p)const {return point(x - p.x, y - p.y);}
};
 
int main() {
	int n;
	dato a, b, base, h;
	vector<dato> v;
	vector<point> points;
	cin >> n;
 
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		point p(a, b);
		points.push_back(p);
	}
	for(int i = 0; i < n; i++) {
		//Get base
		dato aux= (points[(i+1)%n] - points[i]).cross(points[(i+2)%n] - points[i]);
		v.push_back(aux);
	}
	sort(v.begin(), v.end());
	dato result = v[n-1] / 2;
 
	cout << std::setprecision(10) << fixed;
	cout << result << endl;
}
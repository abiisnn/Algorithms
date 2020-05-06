#include<bits/stdc++.h>
using namespace std;
using dato = long double;
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
	dato norm() const{return x * x + y * y;}
	point operator-(const point & p) const {return point(x - p.x, y - p.y);}
	point operator+(const point & p) const{return point(x +p.x, y + p.y);}
	point operator*(const dato & k) const{return point(x * k, y * k);}
	point operator/(const dato & k) const{return point(x / k, y / k);}
	point operator+=(const point & p){*this = *this + p; return *this;}
	point operator-=(const point & p){*this = *this - p; return *this;}
	dato length() const{return sqrtl(x * x + y *y);}
	point unit() const{return (*this) / length();}
};
bool pointInLine(const point & a, const point & v, const point &p) {
	//line a+tv, point p
	return eq((p - a).cross(v), 0);
}
bool pointInSegment(const point & a, const point & b, const point &p) {
	//segment ab, point b
	return pointInLine(a, b - a, p) && leq((a - p).dot(b - p), 0);
}	
int sgn(dato x) {
	if(ge(x, 0)) return 1;
	if(le(x, 0)) return -1;
	return 0;
}
int intersectSegmentsInfor(point a, point b, point c, point d) {
	point v1 = b - a, v2 = d - c;
	int t = sgn(v1.cross(c - a)), u = sgn(v1.cross(d - a));
	if(t == u) {
		if(t == 0) {
			if(pointInSegment(a, b, c) || pointInSegment(a, b, d) || pointInSegment(c, d, a) || pointInSegment(c, d, b)) {
				return -1;// infinity points
			} else {
				return 0; //no point
			}
		} else {
			return 0; //no point
		}
	} else {
		return sgn(v2.cross(a - c)) != sgn(v2.cross(b - c));
	}
}
bool pointInPerimeter(vector<point> &P, const point & p) {
	int n = P.size();
	for(int i = 0; i < n; i++) {
		if(pointInSegment(P[i], P[(i + 1) % n], p)) {
			return true;
		}
	}
	return false;
}
bool crossesRay(const point & a, const point & b, const point &p) {
	return ge((geq(b.y, p.y) - geq(a.y, p.y)) * (a -p).cross(b - p), 0);
}
int pointInPolygon(vector<point> & P, const point &p) {
	if(pointInPerimeter(P, p)) {
		return -1; //point in the perimeter
	}
	int n = P.size();
	int rays = 0;
	for(int i = 0; i < n; i++) {
		rays += crossesRay(P[i], P[(i + 1) % n], p);
	}
	return rays & 1; //0: point outside, 1: point inside
}
point intersectLines(const point & a1, const point & v1, const point & a2, const point & v2) {
	//lines a1+tv1, a2+tv2
	//assuming that they intersect
	dato det = v1.cross(v2);
	return a1 + v1 * ((a2 - a1).cross(v2) / det);
}
dato signed_angle(const point & a, const point & b) {
	return sgn(a.cross(b)) * acosl(a.dot(b) / (a.length() * b.length()));
}
int pointInCircle(const point & c, dato r, const point & p) {
	dato l = (p - c).length() - r;
	return(le(l, 0) ? 1 : (eq(l, 0) ? -1 : 0));
}
vector<point> intersectLineCircle(const point & a, const point & v, const point & c, dato r) {
	dato h2 = r*r - v.cross(c - a) * v.cross(c - a) / v.norm();
	point p = a + v * v.dot(c - a) / v.norm();
	if(eq(h2, 0)) return {};
	else {
		point u = v.unit() * sqrt(h2);
		return{p - u, p +u};
	}
}
vector<point> intersectSegmentCircle(const point & a, const point & b, const point & c, dato r) {
	vector<point> P = intersectLineCircle(a, b - a, c, r), ans;
	for(const point & p : P) {
		if(pointInSegment(a, b, p)) ans.push_back(p);
	}
	return ans;
}
dato intesectPolygonCircle(const vector<point> &P, const point & c, dato r) {
	int n = P.size();
	dato ans = 0;
	for(int i = 0; i < n; ++i) {
		point p = P[i], q = P[(i+1)%n];
		bool p_inside = (pointInCircle(c, r, p) != 0);
		bool q_inside = (pointInCircle(c, r, q) != 0);
		if(p_inside && q_inside) {
			ans += (p - c).cross(q - c);
		} else if(p_inside && !q_inside) {
			point s1 = intersectSegmentCircle(p, q, c, r)[0];
			point s2 = intersectSegmentCircle(c, q, c, r)[0];
			ans += (p - c).cross(s1 - c) + r*r * signed_angle(s1 - c, s2 -c);
		} else if(!p_inside && q_inside) {
			point s1 = intersectSegmentCircle(c, p, c, r)[0];
			point s2 = intersectSegmentCircle(p, q, c, r)[0];
			ans += (s2 - c).cross(q - c) + r*r * signed_angle(s1 - c, s2 - c);
		} else {
			auto info = intersectSegmentCircle(p, q , c, r);
			if(info.size() <= 1) {
				ans += r*r * signed_angle(p - c, q - c);
			} else {
				point s2 = info[0], s3 = info[1];
				point s1 = intersectSegmentCircle(c, p, c, r)[0];
				point s4 = intersectSegmentCircle(c, q, c, r)[0];
				ans += (s2 - c).cross(s3 - c) + r*r * (signed_angle(s1 - c, s2 - c) + signed_angle(s3 - c, s4 - c));
			}
		}
	}
	return abs(ans)/2;
}

int main() {
	dato n, r, a, b;
	cin >> n >> r;
	vector<point> points;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		point p(a, b);
		points.push_back(p);
	}
	point c(0, 0);
	cout << std::setprecision(10) << fixed;
	cout << intesectPolygonCircle(points, c, r) << endl;

}
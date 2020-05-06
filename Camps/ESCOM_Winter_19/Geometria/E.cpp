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
	point operator-(const point & p) const {return point(x - p.x, y - p.y);}
	point operator+(const point &p) const{return point(x +p.x, y + p.y);}
	point operator*(const dato &k) const{return point(x * k, y * k);}
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
int main() {
	int x, y;
	vector<point> A;
	vector<point> B;
 
	for(int i = 0; i < 4; i++) {
		cin >> x >> y;
		point p(x, y);
		A.push_back(p);
	}
	for(int i = 0; i < 4; i++) {
		cin >> x >> y;
		point p(x, y);
		B.push_back(p);
	}
	// Intersect
	int noIntersect = 0;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			if(!intersectSegmentsInfor(A[i], A[(i+1)%4], B[j], B[(j+1)%4])) noIntersect++;			
		}
	}
	if(noIntersect == 16) {
		// Check point in polig
		point midPoint = intersectLines(B[0], B[2]-B[0], B[1], B[3]-B[1]);
		// Point in poli
		if(pointInPolygon(A, midPoint)) cout << "YES" << endl;
		else cout << "NO" << endl;
 
	}
	else cout << "YES" << endl; 
}
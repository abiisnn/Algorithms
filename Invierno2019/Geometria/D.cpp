#include<bits/stdc++.h>
using namespace std;
using dato = long double;
dato eps = 1e-9; 
typedef long long int lli;
struct point {
	dato x, y;
	point():x(0), y(0){}
	point(dato x, dato y): x(x), y(y){}
	dato cross(const point & p)const {return x * p.y - y * p.x;}
};

lli comb(lli n) {
	return (n * (n - 1) * (n - 2)) / 6;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	lli n, a, b;
	map<tuple<int, int, int>, set<pair<int, int>>> lines;
	vector<point> P;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		point p(a, b);
		P.push_back(p);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			int a = P[j].y - P[i].y;
			int b = P[i].x - P[j].x;
			int c = (P[i].x * P[j].y) - (P[j].x * P[i].y);
			if(a < 0) {
				a *= -1;
				b *= -1;
				c *= -1;
			}
			if((!a) && (b < 0)) {
				b *= -1;
				c *= -1;
			}
			int g1 = abs(__gcd(b, c));
			int g = abs(__gcd(g1, a));

			a /= g; b /= g; c /= g;
			lines[make_tuple(a, b, c)].insert(make_pair(P[i].x, P[i].y));
			lines[make_tuple(a, b, c)].insert(make_pair(P[j].x, P[j].y));
		}
	}
	lli total = comb(n);
	for(auto &x : lines) {
		total -= comb(x.second.size());
	}
	cout << total << endl;
}
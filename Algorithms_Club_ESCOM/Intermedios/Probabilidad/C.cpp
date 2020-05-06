#include<bits/stdc++.h>
#define MAX 12
using namespace std;
typedef long long int lli;

double rango(double l, double r, double p) {
	lli rp = r / p;
	lli lp = (l - 1) / p;
	return rp - lp;
}

double totales(double l, double r) {
	return r - l + 1;
}
double ps(double l, double r, double p) {
	return rango(l, r, p) / totales(l, r);
} 

double pSyS(double l1, double r1, double l2, double r2, double p) {
	return (rango(l1, r1, p) * rango(l2, r2, p)) / (totales(l1, r1) * totales(l2, r2));
}
double prob(double l1, double r1, double l2, double r2, double p) {
	double s1 = ps(l1, r1, p);
	double s2 = ps(l2, r2, p);
	double s3 = pSyS(l1, r1, l2, r2, p);
	return s1 + s2 - (s1 * s2);
}

int main() {
	double p, l, r, Ex;
	lli n;
	vector<pair<double, double>> v;
	cin >> n >> p;

	v.push_back(make_pair(0, 0));
	for(int i = 0; i < n; i++) {
		cin >> l >> r;
		v.push_back(make_pair(l, r));
	}	
	Ex = 0.0;
	for(int i = 1; i <= n; i++) {
		Ex += (2000.0 * prob(v[i].first, v[i].second, v[(i % n) + 1].first, v[(i % n) + 1].second, p));
	}
	cout << fixed << showpoint;
	cout << setprecision(10) << Ex << endl;
}
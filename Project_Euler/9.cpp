#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
#define N 1000
#define M 1000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<lli> v(N);
map<lli, int> bucket;

bool isPythagoreanTriplet(lli &a, lli &b, lli &c) {
	for(int i = 0; i < v.size(); i++) {
		lli searching = c - v[i];
		if(bucket[searching]) {
			a = v[i];
			b = searching;
			if(sqrt(a) + sqrt(b) + sqrt(c) == 1000) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	v[0] = 10;
	for(int i = 1; i < v.size(); i++) {
		v[i] = i;
	}
	for(int i = 0; i < v.size(); i++) 
		v[i] = v[i] * v[i];

	for(int i = 0; i < v.size(); i++) 
		bucket[v[i]]++;

	/* Search if there are a pair of a and b 
	where a + b = c*/
	for(int i = 0; i < v.size(); i++) {
		lli a, b;
		if(isPythagoreanTriplet(a, b, v[i])) {
			cout << "a: " << sqrt(a) << endl;
			cout << "b: " << sqrt(b) << endl;
			cout << "c: " << sqrt(v[i]) << endl;
			lli ans = sqrt(a) * sqrt(b)*sqrt(v[i]);
			cout << "ans: " << ans << endl;
		}
	}
}
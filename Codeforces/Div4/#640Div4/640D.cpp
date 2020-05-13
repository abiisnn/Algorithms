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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

void changeState(bool &A, bool &B, lli &Alice, lli &Bob, lli actual) {
	if(A) {
		B = true;
		A = false;
		Alice += actual;
	} else {
		A = true;
		B = false;
		Bob += actual;
	}
}

void solve() {
	int n;
	cin >> n;
	vector<int> v(n);
	fore(i, 0, n) cin >> v[i];
	int i = 0, j = n-1, moves = 0;
	bool A = true, B = false;
	lli Alice = 0, Bob = 0, last = 0, actual = 0;
	while(i <= j) {
		if(A) {
			actual += v[i];
			i++;
		}
		if(B) {
			actual += v[j];
			j--;
		}
		if(actual > last) {
			last = actual;
			changeState(A, B, Alice, Bob, actual);
			actual = 0;
			moves++;
		}
	}
	if(actual) {
		changeState(A, B, Alice, Bob, actual);
		moves++;
	}
	cout << moves << " " << Alice << " " << Bob << endl;
}
int main() {
	optimizar_io
	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}
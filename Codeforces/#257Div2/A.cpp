#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'

int main() {
	optimizar_io
	int n, max, pos;
	double div, m;
	cin >> n >> m;
	vector<double> a(n, 0);

	fore(i, 0, n) {
		cin >> a[i];
		a[i] = ceil(a[i] / m);
	}

	max = 0, pos = 0;
	fore(i, 0, n) {
		if(a[i] >= max) {
			max = a[i];
			pos = i;
		}
	}
	cout << pos + 1 << endl;
}
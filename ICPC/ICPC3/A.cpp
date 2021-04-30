#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;


int calculate(int num) {
	if(num >= 500) num -= 100;
	return num;
}

int main() {
	optimizar_io
	vector<int> v(3); 
	fore(i, 0, 3) cin >> v[i];

	sort(all(v));

	int best = 10000;
	do {
		// take first
		int here = calculate(v[0]) + calculate(v[1]+v[2]);
		best = min(best, here);
	} while(next_permutation(all(v)));
	cout << best << endl;
}
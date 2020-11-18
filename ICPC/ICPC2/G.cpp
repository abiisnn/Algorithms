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
#define MAX 55
#define MAXn 105
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<int> box(MAXn);
int main() {
	optimizar_io
	int n; cin >> n;
	fore(i, 0, n) cin >> box[i];

	lli untilHere = 100; 
	lli second = 100;
	lli bestAns = 100;
	fore(i, 0, n) {
		second += box[i];
		bestAns = max(bestAns, max(untilHere, second));
		untilHere += box[i]; 
	}
	bestAns = max(bestAns, max(untilHere, second));
	cout << bestAns << endl;
}
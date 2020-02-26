#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 1000000005
typedef long long int lli;

int main() {
	int n, m;
	lli l, r;

	cin >> n;
	lli maxC = 0;
	lli minC = MAX;
	fore(i, 0, n) {
		cin >> l >> r;
		if(l > maxC) maxC = l;
		if(r < minC) minC = r;
	}
	cin >> m;
	lli maxP = 0;
	lli minP = MAX;
	fore(i, 0, m) {
		cin >> l >> r;
		if(l > maxP) maxP = l;
		if(r < minP) minP = r;
	}
	lli way1 = 0;
	lli way2 = 0;

	if(minC <= maxP) {
		way1 = maxP - minC;
	}
	if(minP <= maxC) {
		way2 = maxC - minP;
	}
	if(way1 > way2) cout << way1 << endl;
	else cout << way2 << endl;
}
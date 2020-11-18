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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

lli f(lli n) {
	n++;
	while(!(n % 10)) n /= 10;
	return n;
}

int main() {
	lli n; cin >> n;
	lli result;

	set<lli> exist;
	exist.insert(n);
	
	while(1) { // 91 iteraciones
		lli result = f(n);
		if(exist.count(result)) break;
		exist.insert(result);
		n = result;
	}
	cout << exist.size()<< endl;
}
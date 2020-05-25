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

int main() {
	optimizar_io
	int a, b, t; cin >> t;
	while(t--) {
		cin >> a >> b;
		int op1 = 100000, op2 = 100000, op3 = 100000, op4 = 100000;
	
		if((a+a) >= (b)) op1 = (a+a) * (a+a);
		if((b+b) >= (a)) op2 = (b+b) * (b+b);
		if(b >= (a+a)) op3 = b * b;
		if(a >= (b+b)) op4 = a * a;
		// cout << op1 << " " << op2 << endl;
		// cout << op3 << " " << op4 << endl;
		cout << std::min(std::min(op1, op4),std::min(op2, op3)) << endl;
	}
	
}
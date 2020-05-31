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
#define MAX 37
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	string a, b;
	cin >> a >> b;
	if(a == b) {
		cout << "Yes" << endl;
		return 0;
	}
	bool flag = true;
	if(abs(a.size() - b.size()) > 3) flag = false;
	else {
		
	}
}
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
	string n;
	int k;
	cin >> n >> k; 
	
	bool flag = false;
	int zero = 0, normales = 0;
	for(int i = n.size()-1; i>= 0; i--) {
		if(zero == k) {
			flag = true;
			break;
		}
		if(n[i] == '0') zero++;
		else normales++;
	}
	if(flag) cout << normales << endl;
	else cout << n.size()-1 << endl;
}
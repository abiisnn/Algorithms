#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isBeutiful(lli n) {
	string num = to_string(n);
	fore(i, 0, num.size()) {
		if((num[i] == '0') or (num[i] == '5')) continue;
		else return false;
	}
	return true;
}

int main() {
	optimizar_io
	lli a = 90;
	for(int i = 0; i < 10000; i++) {
		if(isBeutiful(a*i)) cout << a*i << " ";
	} 
}
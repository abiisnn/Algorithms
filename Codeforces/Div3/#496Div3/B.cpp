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

int main() {
	optimizar_io
	string a, b; cin >> a >> b;	
	int equal = 0;
	for(int i = a.size()-1, j = b.size()-1; i >= 0 && j >= 0; i--, j--) {
		if(a[i] != b[j]) break;
		equal++;
	}
	cout << a.size() + b.size() - 2*equal << endl;
}



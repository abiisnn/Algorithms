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

lli MEX(set<lli> st) { // O(|st| * log(|st|))
	for(lli i = 0;; i++) {
		if(!st.count(i)) return i;
	}
}
int main() {
	optimizar_io
	int n;
	string aux;
	cin >> n;
	set<lli> st;
	fore(i, 0, n) {
		cin >> aux;
	    if(aux.size() < 19) {
	    	stringstream geek(aux); 
		    lli x = 0; 
			geek >> x; 
			if(x >= 0) st.insert(x);	
	    } 
	}
	cout << MEX(st) << endl; 
}
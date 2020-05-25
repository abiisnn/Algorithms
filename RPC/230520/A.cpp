#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;
typedef long double ld;
ld eps = 1e-6;

bool geq(ld a, ld b){return a-b >= -eps;} // a >= b
bool ge(ld a, ld b){return a-b > eps;} // a > b
bool le(ld a, ld b){return b-a > eps;} // a < b
bool leq(ld a, ld b){return b-a >= -eps;} // a <= b
bool eq(ld a, ld b){return abs(a-b) <= eps;} // a == b
int main(){
	int n,m; cin>>n>>m;
	vector <ld> v(n,1);
	map<int, ld> intentos;
	ld last = 1;
	for(int i=0; i<m; i++){
		int a,b;  ld p; cin>> a >> b >> p;
		// v[b-1] = (1-p) * ((v[a-1] * v[b-1]) / last);
		if(!intentos[b]) last = 1;
		else last = intentos[b];
		// v[b-1] = last * (1- p) * v[a-1]; 
		v[b-1] = (1 - (v[a-1]*p*(1-last)));
		intentos[b] = p;
	}
	cout << setprecision(10) << fixed;
	for(int i=0; i<n; i++)
		cout<<v[i]<<endl;
	return 0;
}
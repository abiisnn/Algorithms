#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define MAX 5005
typedef long long int lli;

int main() {
	optimizar_io
	int t;
	lli a, b;
	cin >> t;
	while(t--) {
		cin >> a >> b;
		lli ineed = a % b;
		if(ineed) cout << b - ineed << endl;
		else cout << "0" << endl;
	}
}
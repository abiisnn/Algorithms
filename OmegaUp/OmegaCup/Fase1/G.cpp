#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;
typedef unsigned long long int ulli;


int main() {
	optimizar_io
	int k;
	cin >> k;
	set<pair<int, int>> p;
	for(int i = k+1; i <= k*2; i++) {
		int num = i - k;
		int den = k * i;
		int ans = den / num;
		if((den % num) == 0) {
			p.insert(mk(i, ans));
		}
	}
	cout << p.size() << endl;
	for(auto &i: p) {
		cout << "1/" << k << " = 1/" << i.second << " + 1/" << i.first << endl; 
	}
}
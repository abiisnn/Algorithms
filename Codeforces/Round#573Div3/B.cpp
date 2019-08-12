// https://codeforces.com/contest/1196/problem/A
#include<bits/stdc++.h>
#include <math.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main() {
	ll q, n, k;
	ll i, j;
	ll number, oddCont, res;
	int flag;
	cin >> q;
	while(q--) {
		cin >> n >> k;
		vector<ll> odds;
		oddCont = 0; flag = 0;
		for(i = 0; i < n; i++) {
			cin >> number;
			if(number & 1) {
				odds.push_back(number);
				oddCont++;
			}			
		}
		if(oddCont >= k) {
			res = oddCont - k;
			if((res == 0) || ((res % k) == 0)) {
				res = odds.size() / k;
				cout << "YES" << endl;
				for(i = odds.size() - 1; i >= 1; i -= res) 
					cout << odds[i] << " ";
				cout << n << endl;
			} 
			else cout << "NO" << endl;
		}
		else cout << "NO" << endl;
	}
}
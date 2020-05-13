// https://codeforces.com/contest/1196/problem/A
#include<bits/stdc++.h>
#include <math.h>

using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main() {
	ll q, a, b, c;
	ll sum;
	cin >> q;
	while(q--) {
		cin >> a >> b >> c;
		sum = a + b + c;
		if(sum & 1) 
			sum = (sum - 1) / 2;
		else
			sum /= 2;
		cout << sum << endl; 
	}
}
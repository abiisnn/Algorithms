// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3834
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main() {
	int tc;
	string query;
	ll n, sum = 0;
	cin >> tc;
	while(tc) {
		cin >> query;
		if(!query.compare("donate")) {
			cin >> n;
			sum += n;
		}
		else 
			cout << sum << endl;
		tc--;
	}
}
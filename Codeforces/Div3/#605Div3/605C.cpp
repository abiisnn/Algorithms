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
#define MAX 100005
typedef long long int lli;

lli gauss(lli n) {
	return (n * (n+1)) / 2;
}
int main() {
	optimizar_io
	lli n;
	int k;
	string s;
	char aux;
	cin >> n >> k >> s;
	set<char> icanUse;
	fore(i, 0, k) {
		cin >> aux;
		icanUse.insert(aux);
	}
	lli times = 0, ans = 0;
	fore(i, 0, s.size()) {
		if(icanUse.count(s[i])) times++;
		else {
			ans += gauss(times);
			times = 0;
		}
	}
	ans += gauss(times);
	cout << ans << endl;
}
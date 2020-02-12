// https://vjudge.net/contest/353813#problem/D
// https://codeforces.com/problemset/problem/702/B
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

void generatePowers(vector<lli> &v) {
	fore(i, 1, 32) {
		lli a = 1;
		a = a << i;
		v.pb(a);
	}
}
int main() {
	int n;
	lli ans;
	cin >> n;
	vector<lli> powers;
	map<lli, lli> bucket;
	vector<lli> a(n, 0);
	fore(i, 0, n) {
		cin >> a[i];
		bucket[a[i]]++;
	}
	
	generatePowers(powers);
	ans = 0;	
	fore(i, 0, powers.size()) {
		map<lli, lli> aux = bucket;
		fore(j, 0, a.size()) {
			aux[a[j]]--;
			if(a[j] < powers[i]) ans += aux[powers[i] - a[j]];
		}			
	}
	cout << ans;
}
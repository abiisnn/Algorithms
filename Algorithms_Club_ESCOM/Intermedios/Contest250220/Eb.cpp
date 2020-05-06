// Using binary search
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
#define MAX 1000000005
typedef long long int lli;

int main() {
	optimizar_io

	int n;
	lli sum, ans, l, r, m;
	cin >> n;

	vector<lli> num(n, 0);
	l = 0, sum = 0;
	fore(i, 0, n) {
		cin >> num[i];
		if(num[i] > l) l = num[i];
		sum += num[i]; 
	} 

	r = 1LL << 32;
	ans = -1;
	while(l <= r) {
		m = l + (r - l) / 2;
		if((m * (n - 1)) >= sum) {
			ans = m;
			r = m - 1;
		} 
		else l = m + 1;
	}
	cout << ans << endl;
}
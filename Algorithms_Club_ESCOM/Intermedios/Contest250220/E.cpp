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
	lli greater, sum, ineed, ans;
	cin >> n;

	vector<lli> num(n, 0);
	greater = 0;
	sum = 0;
	fore(i, 0, n) {
		cin >> num[i];
		if(num[i] > greater) greater = num[i];
		sum += num[i]; 
	} 
	ineed = greater * (n - 1);
	if(ineed >= sum) {
		ans = greater;
	} else {
		ineed = sum - ineed;
		ans = greater + floor(ineed / (n-1));
		if(ineed % (n-1)) ans++;
	}
	cout << ans << endl;
}
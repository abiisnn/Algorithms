#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define pairs pair<int, int>
#define fi first
#define se second
#define endl '\n'
#define N 3
typedef long long int lli;


int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<lli> a(n, 0);
	lli max = 0;
	fore(i, 0, n) {
		cin >> a[i];
		if(a[i] > max) {
			max = a[i];
		}
	}
	cout << max << endl;
}
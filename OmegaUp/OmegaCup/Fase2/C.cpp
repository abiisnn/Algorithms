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
#define MAX 1000005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n;
	cin >> n;
	lli aux;
	vector<int> nums(n);
	fore(i, 0, n) {
		cin >> nums[i];
	}
	lli ans = 0;
	for(int i = 0; i < n; i++) {
		lli andAcum = nums[i];
		for(int j = i+1; j < n; j++) {
			// if(nums[j] != nums[i]) ans++;
			lli aux = andAcum & nums[j];
			if(!aux) ans++;
			andAcum = aux;
		}
	}
	cout << ans << endl;
}
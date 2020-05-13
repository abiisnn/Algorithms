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
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int pot(int n) {
	int ans = 1;
	for(int i = 0; i < n; i++) ans *= 10;
	return ans;
}

void solve(int n) {
	vector<int> num;
	int i = 0;
	while(n) {
		int aux = n % 10;
		if(aux != 0) {
			aux *= pot(i); 
			num.pb(aux);
		}
		n /= 10;
		i++;
	}
	cout << num.size() << endl;
	fore(i, 0, num.size()) {
		cout << num[i] << " ";
	}
	cout << endl;
}

int main() {
	optimizar_io
	int t, n;
	cin >> t;

	while(t--) {
		cin >> n;
		solve(n);
	}


}
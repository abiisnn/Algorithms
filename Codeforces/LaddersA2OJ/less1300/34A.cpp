#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<int> num(n, 0);
	for(int i = 0; i < n; i++) cin >> num[i];
	int disMax = 10000;
	int ans = -1;
	for(int i = 0; i < n-1; i++) {
		if(abs(num[i] - num[i+1]) < disMax) {
			ans = i;
			disMax = abs(num[i] - num[i+1]);
		}
	}
	if(abs(num[0] - num[num.size()-1]) < disMax) {
		cout << num.size() << " " << 1 << endl;
	} else {
		cout << ans +1<< " " << ans+2 << endl;
	}
}
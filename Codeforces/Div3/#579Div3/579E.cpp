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

int main() {
	optimizar_io
	int n;
	int last = 150005;
	int ans = 0;
	cin >> n;
	vector<int> aux(n);
	fore(i, 0, n) cin >> aux[i];
	sort(aux.begin(), aux.end());

	for(int i = n-1; i>= 0; i--) {
		if((aux[i] + 1) < last) {
			last = aux[i] + 1;
			ans++;
		} else if(aux[i] < last) {
			last = aux[i];
			ans++;
		} else if((aux[i] - 1) < last && (aux[i] -1) > 0) {
			last = aux[i] - 1;
			ans++;
		}
	}
	cout << ans << endl;
}
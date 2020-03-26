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
	string a, b;
	cin >> a >> b;

	bool ans = true;
	if(a.size() == b.size()) {
		int j = b.size()-1;
		fore(i, 0, a.size()) {
			if(a[i] != b[j]) {
				ans = false;
				break;
			}
			j--;
		}

	} else ans = false;
	if(ans) cout << "YES" << endl;
	else cout << "NO" << endl;
}
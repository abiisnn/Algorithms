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
	lli num, pos = 0, less = 1000000005;
	cin >> n;
	map<lli, int> m;
	for(int i = 0; i < n; i++) {
		cin >> num;
		m[num]++;
		if(num < less) {
			less = num;
			pos = i;
		}
	}
	if(m[less] > 1) cout << "Still Rozdil" << endl;
	else cout << pos+1 << endl;
}
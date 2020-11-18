#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool check(set<lli> &exist, lli point, lli dis, lli acum) {
	lli current = (point + dis) % acum;
	lli third = current + dis % acum;
	if(exist.count(current) && exist.count(third)) {
		exist.erase(current);
		exist.erase(third);
		return true;
	}
	return false;
}
int main() {
	optimizar_io
	int n, ele; cin >> n;
	vector<lli> points(n);
	set<lli> exist;
	lli acum = 0;
	fore(i, 0, n) {
		cin >> ele;
		acum += ele;
		points[i] = acum;
		exist.insert(acum);
	}
	lli dis = acum / 3;
	int ans = 0;
	fore(i, 0, n) {
		if(check(exist, points[i], dis, acum)) {
			ans++;
		}
	}
	cout << ans << endl;
}
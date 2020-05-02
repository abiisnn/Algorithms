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
#define MAX 105
#define MOD 1000000007 
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
bool leq(ld a, ld b){return b-a >= -eps;}     //a <= b
int binaryL(vector<int>&C, int target) {
	int l = 0, r = C.size()-1, ans = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(C[mid] > target) r = mid-1;
		else {
			l = mid+1;
			ans = mid;
		}
	}
	return ans;
}
int binaryR(vector<int>&C, int target) {
	int l = 0, r = C.size()-1, ans = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(C[mid] >= target) {
			ans = mid;
			r = mid - 1;
		} else l = mid + 1;
	}
	return ans;
}
ld distance(int x, int y, int l) {
	ld dis = (((ld)x - l) * ((ld)x - l)) + (((ld)y - 0) * ((ld)y - 0));
	return sqrt(dis); 
}
int main() {
	optimizar_io
	int n, m, x, y, cont = 0; 
	ld r;
	cin >> n;
	vector<pair<int, int>> Cpos;
	vector<int> C(n), ans(n, -1);
	vector<ld> R(n);
	fore(i, 0, n) {
		cin >> x >> r;
		Cpos.pb(mk(x, i));
		R[i] = r;
	}
	cin >> m;
	sort(Cpos.begin(), Cpos.end());
	fore(i, 0, n) C[i] = Cpos[i].fi;

	fore(i, 0, m) {
		cin >> x >> y;
		int l = binaryL(C, x);
		if(l != -1) {
			if(leq(distance(x, y, C[l]), R[Cpos[l].se])) {
				if(ans[Cpos[l].se] == -1) {
					ans[Cpos[l].se] = i+1;
					cont++;
				}
			}
		}
		int r = binaryR(C, x);
		if(r != -1) {
			if(leq(distance(x, y, C[r]), R[Cpos[r].se])) {
				if(ans[Cpos[r].se] == -1) {
					ans[Cpos[r].se] = i+1;
					cont++;
				} 
			}
		}
	}
	cout << cont << endl;
	fore(i, 0, ans.size()) {
		cout << ans[i] << " ";
	}
}
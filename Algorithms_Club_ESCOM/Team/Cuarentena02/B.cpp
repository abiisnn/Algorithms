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
int lowerBound(vector<int> &a, int l, int r, int target) { // O(log(n)
	int ans = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(a[mid] <= target) {
			ans = mid;
			l = mid + 1;
		} else r = mid - 1;
	}
	return ans;
}
int main() {
	int n; 
	cin >> n;
	vector<int> teams(n);
	int minR = 20;
	fore(i, 0, n) {
		cin >> teams[i];
		if(teams[i] < minR) minR = teams[i];
	}
	vector<int> problems(10);
	fore(i, 0, 10) cin >> problems[i];
	sort(problems.begin(), problems.end());
	
	bool flag = true;
	vector<int> pos;
	fore(i, 0, n) {
		int index = lowerBound(problems, 0, problems.size()-1, teams[i]);
		if(index == -1) {
			flag = false;
			pos.pb(teams[i]);
		}
	}	
	sort(pos.begin(), pos.end());
	if(flag) cout << 10 << endl;
	else cout << pos[0] << endl;
}
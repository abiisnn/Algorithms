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
#define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n;
	cin >> n;
	vector<int> nums(n);
	set<int> s;
	vector<int> unicos;
	map<int, int> m;
	fore(i, 0, n) {
		cin >> nums[i];
		if(s.count(nums[i]) == 0) 
			unicos.pb(nums[i]);
		s.insert(nums[i]);
		m[nums[i]]++;
	}
	sort(unicos.begin(), unicos.end());
	
	int pointer = 0;
	int index = 0;
	while(index < n) {
		if(m[unicos[pointer]] > 0) {
			nums[index] = unicos[pointer];
			m[unicos[pointer]]--;
			index++;
		}
		pointer++;
		if(pointer == unicos.size()) pointer = 0;
	}
	int ans = 0;
	fore(i, 1, n) {
		if(nums[i] > nums[i-1]) ans++;
	}
	cout << ans << endl;
}
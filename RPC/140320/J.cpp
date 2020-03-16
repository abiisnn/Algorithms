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
#define MAX 10000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

pair<int, int> convert(string h) {
	pair<int, int> ans = mk(0, 0);
	string minutes = "";
	minutes.pb(h[0]);

	string seconds = "";
	seconds.pb(h[2]);
	seconds.pb(h[3]);
	
	stringstream aux(minutes);
	aux >> ans.first;

	stringstream auxsec(seconds);
	auxsec >> ans.second; 
	return ans;
}

int main() {
	optimizar_io
	int n, c;
	int hours = 0, minutes = 0, seconds = 0;
	string s;
	cin >> n >> c;
	fore(i, 0, n) {
		cin >> s;
		pair<int, int> hour = convert(s);
		minutes += hour.first;
		seconds += hour.second;
	}
	seconds += (minutes * 60);
	seconds -= (n - 1) * c;

	minutes = seconds / 60;
	seconds %= 60;

	hours = minutes / 60;
	minutes %= 60;

	if(hours < 10) cout << "0";
	cout << hours << ":";
	if(minutes < 10) cout << "0";
	cout << minutes << ":";
	if(seconds < 10) cout << "0";
	cout << seconds << endl;
}
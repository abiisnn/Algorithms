// https://codeforces.com/contest/1294/problem/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

void printAns(vector<pair<int, int>> &p) {
	cout << "YES" << endl;
	int lastX = 0, lastY = 0, max = 0;
	for(int i = 0; i < p.size(); i++) {
		for(int j = 0; j < p[i].first - lastX; j++) cout << "R";
		for(int j = 0; j < p[i].second - lastY ; j++) cout << "U"; 
		lastY = p[i].second;
		lastX = p[i].first;
	} cout << endl;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t, n, x, y, last;
	bool flag;
	cin >> t;
	while(t--) {
		cin >> n;
		vector<pair<int, int>> packets;
		for(int i = 0; i < n; i++) {
			cin >> x >> y;
			packets.pb(mp(x, y));
		}
		sort(packets.begin(), packets.end());
		
		flag = true, last = 0;
		for(int i = 0; i < n; i++) {
			if(packets[i].second < last) {
				flag = false;
				break;
			}
			last = packets[i].second;
		}
		if(flag) printAns(packets); 
		else cout << "NO" << endl;
	}
}
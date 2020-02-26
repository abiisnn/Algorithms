//https://codeforces.com/contest/272/problem/A
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
typedef long long int lli;

int main() {
	optimizar_io
	int n, places, ans, dis;
	cin >> n;
	vector<int> fingers(n, 0);
	places = 0;
	fore(i, 0, n) {
		cin >> fingers[i];
		places += fingers[i];
	}
	n++;
	ans = (places % n);
	dis = max(ans, n) - min(ans, n) + 1;
	ans = dis % 6;
	ans++;
	if(ans & 1) cout << "3" << endl;
	else cout << "2" << endl;
}
// https://codeforces.com/contest/264/problem/A
// https://vjudge.net/contest/353813#problem/O
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define pf push_front
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	string s;
	cin >> s;
	vector<int> R;
	deque<int> L;
	fore(i, 0, s.size()) {
		if(s[i] == 'l') L.pf(i + 1);
		else R.pb(i + 1);
	}
	fore(i, 0, R.size()) cout << R[i] << endl;
	fore(i, 0, L.size()) cout << L[i] << endl;
}
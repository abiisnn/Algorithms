// https://vjudge.net/contest/353813#problem/A
// https://codeforces.com/problemset/problem/1234/B2
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
	int n, k, pos;
	lli num;
	cin >> n >> k;
	deque<lli> screen;
	set<lli> isIn;
	while(n--) {
		cin >> num;
		if(isIn.count(num)) continue;
		if(screen.size() == k) {
			isIn.erase(screen[screen.size() - 1]);
			screen.popb();
		}
		isIn.insert(num);
		screen.push_front(num);
	}
	cout << screen.size() << endl;
	fore(i, 0, screen.size()) cout << screen[i] << " ";
	cout << endl;
}
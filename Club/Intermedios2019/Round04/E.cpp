// https://codeforces.com/group/jbdVtsXBjp/contest/258964/problem/E
#include<bits/stdc++.h>
#define MAXN 57
typedef long long int lli;
using namespace std;
int search(string &str, int k, char a) {
	for(int i = k; i < str.size(); i++) 
		if(str[i] == a) return i;
	return -1;
}

void makeSwap(string &a, string &b, int A, int B) {
	a[A] = a[A] xor b[B];
	b[B] = a[A] xor b[B];
	a[A] = a[A] xor b[B];
}
void printMoves(vector<pair<int,int>> m) {
	cout << "Yes" << endl;
	cout << m.size() << endl;
	for(int i = 0; i < m.size(); i++) 
		cout << m[i].first + 1 << " " << m[i].second + 1 << endl;
}
int main() {
	int k, n, i, j;
	string s, t;
	cin >> k;
	while(k--) {
		cin >> n >> s >> t;
		vector<pair<int, int>> v;
		bool flat = true;
		for(i = 0; i < s.size(); i++) {
			if(s[i] == t[i]) continue;
			int in = search(s, i + 1, s[i]);
			int inDown = search(t, i + 1, s[i]);
			if(in != -1) {
				v.push_back(make_pair(in, i));
				makeSwap(s, t, in, i);
			}
			else if(inDown != -1) {
				v.push_back(make_pair(i + 1, inDown));
				makeSwap(s, t, i + 1, inDown);
				v.push_back(make_pair(i + 1, i));
				makeSwap(s, t, i + 1, i);
			}
			else {
				flat = false;
				break;
			}
		}
		if((v.size() <= (2 * n)) && flat) printMoves(v);
		else cout << "No" << endl;
	}
}
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
#define MAX 105
typedef long long int lli;

int main() {
	optimizar_io
	int q;
	cin >> q;

	while(q--) {
		string s;
		cin >> s;
		map<char, int> bucket;
		fore(i, 0, s.size()) {
			bucket[s[i]]++;
		}
		int minLR = min(bucket['L'], bucket['R']);
		int minUD = min(bucket['U'], bucket['D']); 	
		if(minLR == 0 && minUD > 0) cout << 2 << endl << "UD" << endl;
		else if(minUD == 0 && minLR > 0) cout << 2 << endl << "LR" << endl;
		else {
			cout << minLR * 2 + minUD * 2 << endl;
			fore(i, 0, minLR) cout << "R";
			fore(i, 0, minUD) cout << "U";
			fore(i, 0, minLR) cout << "L";
			fore(i, 0, minUD) cout << "D";
			cout << endl;
		}
 	}
	return 0;
}
// https://codeforces.com/contest/1272/problem/B
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100002
#define optimizar_io ios_base::sync_with_stdio(0); 
typedef long long int lli;

int main() {
	int q;
	cin >> q;

	while(q--) {
		string s;
		vector<int> v(4, 0);
		cin >> s;
		
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'L') v[0]++;
			else if(s[i] == 'R') v[1]++;
			else if(s[i] == 'U') v[2]++;
			else v[3]++;
		}	
		int x = min(v[0], v[1]);
		int y = min(v[2], v[3]);

		if((v[0] == v[1]) and (v[0] != 0)) x = 1;
		if((v[2] == v[3]) and (v[2] != 0)) y = 1;
		cout << (x * 2) + (y * 2) << endl;
		for(int i = 0; i < x; i++) cout << "L";
		for(int i = 0; i < x; i++) cout << "R";
		for(int i = 0; i < y; i++) cout << "D";
		for(int i = 0; i < y; i++) cout << "U";
		
		cout << endl;
 	}
	return 0;
}
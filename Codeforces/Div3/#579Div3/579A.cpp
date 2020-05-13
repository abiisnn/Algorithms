// https://codeforces.com/contest/1203/problem/A
#include<bits/stdc++.h>
 using namespace std;
 
int main() {
	int tc;
	int n, f, s, number;
	int flag, cont, final;
	cin >> tc;
	while(tc--) {
		cin >> n;
		vector<int> v;
		for(int i = 0; i < n; i++) {
			cin >> number;
			v.push_back(number);
		}
		if(v.size() == 1) cout << "YES" << endl;
		else {
			f = v[0];
			s = v[1];
			// flag 1 : ASC
			//		0 : DES
			flag = 0; cont = 0;
			if((f - s) == 1) flag = 0;
			else if((s - f) == 1) flag = 1;
			else if((f == n) && (s == 1)) flag = 1;
 
			if(flag) { // ASC
				cont = v[0]; final = 0;
				for(int i = 0; i < v.size(); i++) {
					if(cont != v[i]) {
						final = 1;
						break;
					}
					cont %= n; 
					cont++;
				}
			} else {
				cont = v[0]; final = 0;
				for(int i = 0; i < v.size(); i++) {
					if(cont != v[i]) {
						final = 1;
						break;
					}
					if(cont == 1) cont = n;
					else cont--;
				}
			}
			if(final) cout << "NO" << endl;
			else cout << "YES" << endl;
		}
	}
 
	return 0;
}
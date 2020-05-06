// https://codeforces.com/contest/1107/problem/A
#include<bits/stdc++.h>
using namespace std;
 
int main() {
	int tc, n;
	string str;
	cin >> tc;
	for(int i = 0; i < tc; i++) {
		cin >> n >> str;
		if(n == 2) {
			if(str[0] >= str[1]) cout << "NO" << endl;
			else cout << "YES" << endl << "2" << endl << str[0] << " " << str[1] << endl;	
		}	
		else {
			cout << "YES" << endl;
			cout << "2" << endl;
			cout << str[0] << " ";
			for(int j = 1; j < str.length(); j++) {
				cout << str[j];			
			}
			cout << endl;
		}
	}
}

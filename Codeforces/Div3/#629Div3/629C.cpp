#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'

typedef long long int lli; 



int main() {
	optimizar_io
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		string str;
		cin >> str;

		int j = n-1; 
		bool greater = true;
		string a = "";
		string b = "";
		for(int i = 0; i < n; i++, j--) {
			if(greater) {
				if(str[i] == '2') {
					a += '1';
					b += '1';
				} else if(str[i] == '1') {
					a += '1';
					b+='0';
					greater = false;
				} else if(str[i] == '0') {
					a += '0';
					b += '0';
				}
			} else {
				if(str[i] == '2') {
					a += '0';
					b += '2';
				} else if(str[i] == '1') {
					a += '0';
					b += '1';
				} else if(str[i] == '0') {
					a += '0';
					b += '0';
				}
			}
		}
		cout << a << endl;
		cout << b << endl;
	}
}
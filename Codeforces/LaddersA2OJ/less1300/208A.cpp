#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 60
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string str, original = "";
	cin >> str;
	int i = 0, last = 0, k = 0;
	bool flag = false;
	if(str.size() < 3) cout << str << endl;
	else {
		while(i < str.size()-2) {
			if(str[i] == 'W' && str[i+1] == 'U' && str[i+2] == 'B') {
				last = i;
				i+=3;
				flag = true;
			} else {
				if(flag) {
					original += " ";
					flag = false;
				} 
				original += str[i];
				i++;	
			}
		}
		int start = last + 3;
		if(start < (str.size()-2)) start = str.size()-2;
		
		if(flag) original += ' ';
		for(int i = start; i < str.size(); i++) original += str[i];
		
		if(original[0] == ' ') k = 1;
		fore(i, k, original.size()) cout << original[i];
		cout << endl;		
	}

}
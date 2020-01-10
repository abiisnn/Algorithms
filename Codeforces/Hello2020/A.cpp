// https://codeforces.com/contest/1284/problem/0
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define N 100002
#define optimizar_io ios_base::sync_with_stdio(0); 
typedef long long int lli;

int main() {
	string aux;
	int s, t, q, year;
	cin >> s >> t;

	vector<string> first;
	vector<string> second;
	for(int i = 0; i < s; i++) {
		cin >> aux;
		first.push_back(aux);
	}
	for(int i = 0; i < t; i++) {
		cin >> aux;
		second.push_back(aux);
	}
	
	cin >> q;
	while(q--) {
		cin >> year;
		int a = ((year - 1) % s) ;
		int b = ((year - 1) % t) ;
		cout << first[a] << second[b] << endl;
	}


}
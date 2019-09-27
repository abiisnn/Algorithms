// https://codeforces.com/problemset/problem/755/B

#include<bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
	int n, m;
	int j, pos, equals;
	string str;
	cin >> n >> m;

	map<string, int> general;
	std::map<string, int>::iterator it;
	vector<int> a(n, 0), b(m, 0);
	vector<int> bucket(10000, 0);
	
	j = 0; equals = 0;
	for(int i = 0; i < n; i++) {
		cin >> str;
		it = general.find(str);
		if(it == general.end()) { // No lo encontre
			general.insert(pair<string, int>(str, j));
			j++;
		}
		pos = general[str];
		a[i] = pos;
	}
	for(int i = 0; i < m; i++) {
		cin >> str;
		it = general.find(str);
		if(it == general.end()) { // No lo encontre
			general.insert(pair<string, int>(str, j));
		} else equals++;
		pos = general[str];
		b[i] = pos;
	}
	// cout << "equals" << equals << endl;
	// cout << "a:" << endl;
	// for(int i = 0; i < n; i++) {
	// 	cout << a[i] << " ";
	// }
	// cout << endl;
	// cout << "b:" << endl;
	// for(int i = 0; i < m; i++) {
	// 	cout << b[i] << " ";
	// }
	// cout << endl;
	n = n - equals;
	m = m - equals;
	if(equals == 0){
		if(n > m) cout << "YES";
		else cout << "NO";
	}
	else {
		if((equals & 1) && (n > m)) cout << "YES";
		if(!(equals & 1) && (n = m)) cout << "NO";
		else cout << "NO";
	}
}

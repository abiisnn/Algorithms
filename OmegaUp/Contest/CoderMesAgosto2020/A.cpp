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
#define MAX 100
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
int n;
vector<string> all(MAX);

bool isUpperCase(char a) {
	return a >= 'A' && a <= 'Z';
}
int get(map<char, char> likes, set<char> &com, char c) {
	int li = 0;
	fore(i, 0, n) {
		char a = all[i][0];
		char b = all[i][2];
		char des = all[i][1];
		if(des == c) {
			auto actual = likes.find(b);
			if(actual->second == a && !com.count(a) && !com.count(b)) {
				com.insert(a);
				com.insert(b);
				li++;
				cout << "entro: " << a << " " << b << endl;
			}
		}
	}
	return li;
}
int main() {
	optimizar_io
	map<char, char> likes;
	map<char, char> tolerates;
	cin >> n;
	
	fore(i, 0, n) {
		cin >> all[i];
		if(all[i][1] == 'L') {
			likes[all[i][0]] = all[i][2];
			cout << all[i][0] << " " << all[i][2] << endl;
		} else {
			tolerates[all[i][0]] = all[i][2];
		}
	}
	set<char> com;
	int total = 0;
	int li = get(likes, com, 'L');
	total += ( li* 4);
	cout << li << endl;
	cout << "----------" << endl;
	int tol = 0;
	fore(i, 0, n) {
		char a = all[i][0];
		char b = all[i][2];
		char des = all[i][1];
		cout << a << " " << b << endl;
		if(!isUpperCase(a) && com.count(a)) continue;
		if(!isUpperCase(b) && com.count(b)) continue;
		cout << "si" << endl;
		if(des == 'T') {
			char actual = tolerates[b];
			cout  << "actual: " << actual << endl;
			if(actual == a) {
				com.insert(b);
				com.insert(a);
				tol++;
			}
		}
	}
	cout <<tol << endl;
	total += (tol * 3);
	cout << total << endl;
	li = 0;
	// fore(i, 0, n) {
	// 	if(!com.count(all[i]) && all[i][1] == 'L' && isUpperCase(all[i][0])) {
	// 		cout << "cuento:"<<all[i] << endl;
	// 		com.insert(all[i]);
	// 		li++;
	// 	}
	// }

	// total += (li * 2);
	// cout << li << endl;
	// cout << "total: " << total << endl;

}
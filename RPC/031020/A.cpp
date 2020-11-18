#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(a) a.begin(),a.end()
#define pb push_back
#define popb pop_back
#define mk make_pair
#define fi first
#define se second
#define endl '\n'
#define MAX 2000000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

set<pair<int, int>> exist;
int convert(string s) {
	stringstream aux(s);
	int n = 0;
	aux >> n;
	return n;
}
void save(string s) {

	string month(s, 0, 2);
	string day(s, 3, 2);

	int m = convert(month);
	int d = convert(day);
	exist.insert(mk(m, d));
}
int main() {
	optimizar_io

	int b; cin >> b;
	string bir;
	for(int i = 0; i < b; i++) {
		cin >> bir;
		save(bir);
	}
	cout << exist.size()<<endl;
}
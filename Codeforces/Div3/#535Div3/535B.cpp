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
	int n;
	cin >> n;
	vector<int> v(n);
	int greater = 0;
	map<int, int> bucket;
	fore(i, 0, n) {
		cin >> v[i];
		bucket[v[i]]++;
		if(v[i] > greater) greater = v[i];
	}

	int pos = 0, pos2 = 0;
	fore(i, 0, n) {
		if(bucket[v[i]] == 2) {
			if(v[i] > pos) pos = v[i];
		} else if(greater % v[i] != 0) {
			if(v[i] > pos2) pos2 = v[i];
		}
	}
	if(pos2 == 0) cout << greater << " "<< pos << endl;
	else cout << greater << " " << pos2 << endl;
}
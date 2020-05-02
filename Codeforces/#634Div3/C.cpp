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
	int t, n, aux;
	cin >> t;
	while(t--) {
		cin >> n;
		map<int, int> bucket;
		fore(i, 0, n) {
			cin >> aux;
			bucket[aux]++;
		}
		int size = 0;
		int greater = 0;
		for(auto &i: bucket) {
			if(i.second > greater) greater = i.second;
			size++;
		}
		int opA = min(size, greater-1);
		int opB = min(size-1, greater);
		cout << max(opA, opB) << endl;
	}
}
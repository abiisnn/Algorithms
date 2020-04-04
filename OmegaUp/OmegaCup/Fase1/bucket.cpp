#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define MAX 1000

int main() {
	optimizar_io
	int n, q, aux, num;
	cin >> n;
	// vector<int> bucket(MAX, 0);
	map<int, int> m;
	for(int i = 0; i < n; i++) {
		cin >> num;
		m[num]++; // bucket[i] = bucket [i] + 1
	}
	cin >> q;
	while(q--) {
		cin >> aux;
		cout << m[aux] << endl;
	}
	// m[key] = value; // mapeo
}
// https://codeforces.com/contest/1203/problem/E
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	lli n, a;
	map<int, int> bucket;

	cin >> n;
	vector<int> v(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
		bucket[v[i]]++;
		bucket[v[i] + 1]++;
		bucket[v[i] - 1]++;
	}

	set<int> exist;
	for(int i = 0; i < n; i++) {
		vector<pair<int, int>> noVisited;
		// cout << "-----------------" << endl;
		for(int j = v[i] - 1; j <= v[i] + 1; j++) {
			set<int>::iterator it = exist.find(j);
			// cout << "Buscando: " << j << endl;
			if((it == exist.end()) && (j != 0)) { // Not Found
				// cout << "No lo encontre" << endl;
				noVisited.pb(mp(bucket[j], j));
			}
		}
		if(noVisited.size()) {
			sort(noVisited.begin(), noVisited.end());
			exist.insert(noVisited[0].second);
		} else continue;
	}
	// cout << endl << "SET" << endl;
	// for(auto &i: exist) {
	// 	cout << i << " ";
	// }
	// cout << endl;
	cout << exist.size() << endl;
}
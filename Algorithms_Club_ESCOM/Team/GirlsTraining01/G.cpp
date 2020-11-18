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

int main() {
	optimizar_io
	int L, C; cin >> L >> C;
	vector<vector<int>> matrix(L, vector<int>(C));
	fore(i, 0, L) {
		fore(j, 0, C) cin >> matrix[i][j];
	}
	vector<int> bucketL(L), bucketC(C);

	fore(i, 0, L) {
		vector<int> aux = matrix[i];
		sort(all(aux));
		fore(j, 0, C) {
			if(matrix[i][j] != aux[j]) {
				bucketC[j]++;
			}
		}
	}

	fore(i, 0, C) {
		vector<int> aux(L);
		fore(j, 0, L) {
			aux[j] = matrix[j][i];
		}
		sort(all(aux));
		fore(j, 0, L) {
			if(matrix[j][i] != aux[j]) {
				bucketL[j]++;
			}
		}
	}

	map<int, int> aux1, aux2;
	fore(i, 0, L) {
		if(bucketL[i]) aux1[bucketL[i]]++;
	}
	fore(i, 0, C) {
		if(bucketC[i]) aux2[bucketC[i]]++;
	}
	if(aux1.size() >= 2 || aux2.size() >= 2) cout << "*" << endl;
	else {
		int ans = 0, greater = 0;
		for(auto &i: aux1) {
			if(i.first > greater) {
				greater = i.second;
			}
		}
		ans += (greater / 2);
		if(greater % 2) ans++;

		greater = 0;
		for(auto &i: aux2) {
			if(i.first > greater) {
				greater = i.second;
			}
		}
		ans += (greater / 2);
		if(greater % 2) ans++;
		cout << ans << endl;
	}

}
/*
2 4 9 -> 3
5 7 8 -> 2
1 3 6 -> 3


5 1 3
6 2 4
9 8 7
- - -
3 3 3

13 14 15 16 -> 2
5 6 7 8 	-> 2
9 10 11 12  -> 2
1 2 3 4     -> 2
17 18 19 20 -> 2

1 3
5 7
9 11
13 15
17 19
2 
*/
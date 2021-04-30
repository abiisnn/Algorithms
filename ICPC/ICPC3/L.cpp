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

bool equals(string &W, string &check, int firstPos) {
	int j = firstPos;
	for(int i = 0, j = firstPos; i < W.size(); i++, j++) {
		j %= check.size();
		if(W[i] != check[j]) return false;
	}
	return true;
}
bool match(string &W, string &check){
	if(W.size() != check.size()) return false;
	for(int i = 0; i < W.size(); i++)
		if(equals(W, check, i)) return true;
	
	return false;
}
int main() {
	optimizar_io
	int n; cin >> n;
	vector<string> v(n, "");
	fore(i, 0, n) cin >> v[i];

	vector<bool> isVisited(n, false);

	int dif = 0;
	fore(i, 0, n) {
		int iam = 0;
		fore(j, 0, n) {
			if(i != j && !isVisited[j]) {
				if(match(v[i], v[j])) {
					iam++;
					isVisited[j] = true;
				}
			}
		}
		if(iam >= 1) {
			dif++;
			isVisited[i] = true;
		}
	}

	fore(i, 0, n) if(!isVisited[i]) dif++;	
	cout << dif << endl;
}
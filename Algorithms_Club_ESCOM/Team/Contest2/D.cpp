#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
#define MAX 100
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	int n, m;
	int aux = 1;
	while(cin >> n >> m) {
		if(aux != 1) {
			cout << endl;
		}
		vector<int> sum(MAX, 0);

		for(int i = 1; i <= n; i++) {
			int l = i + 1;
			int r = i + m;
			sum[l]++;
			sum[r+1]--;
		}
		for(int i = 1; i < MAX; i++) {
			sum[i] += sum[i-1];
		}
		int max = 0;
		for(int i = 0; i < MAX; i++) {
			if(sum[i] > max) max = sum[i];
		}
		set<int> ans;
		for(int i = 0; i < MAX; i++) {
			if(sum[i] == max) {
				ans.insert(i);
			}
		}
		for(auto &i: ans) {
			cout << i << endl;
		} 
		aux++;
	}
}

#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define endl '\n'
#define MAX 5005
typedef long long int lli;

int main() {
	int t, n;
	cin >> t;
	while(t--) {
		cin >> n;
		bool even = false;
		int pos = 0;
		int odd = 0;
		vector<int> a(n, 0);
		for(int i = 0; i < n; i++) {
			cin >> a[i];
			if(a[i] & 1) odd++;
			else {
				even = true;
				pos = i + 1;
			}
		}
		if(even) {
			cout << "1" << endl;
			cout << pos << endl;
		} else if(odd >= 2){
			odd = 0;
			cout << "2" << endl;
			for(int i = 0; i < n; i++) {
				if(odd == 2) break;
				if(a[i] & 1) {
					cout << i + 1 << " ";
					odd++;
				}
			} cout << endl;
		} else {
			cout << "-1" << endl;
		}

	}
}
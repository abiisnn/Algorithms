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
#define MAX 301
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string N, M;
	string a, name, c, d;
	getline(cin, N);
    stringstream aux(N); 
  
    int n = 0, m = 0; 
    aux >> n;
	getline(cin, M);
    stringstream aux2(M); 
    aux2 >> m;
	map<string, int> ma;
	
	fore(i, 0, n) {
		getline(cin, a);
		fore(j, 0, a.size()) {
			if(a[j] == ' ') {
				name = "";
				int k = j+1;
				while(a[k] != ' ') {
					name += a[k];
					k++;
				}
				ma[name] = i;
				break;
			}
		}
	}
	fore(i, 0, m) {
		getline(cin, a);
		string A = "", B = "";
		int j = 0;
		for(j = 0; j < a.size(); j++) {
			if(a[j] == ' ') break;
			A += a[j];
		}
		for(j = j+3; j < a.size()-1; j++) {
			B += a[j];
		}
		ma[A] = ma[B]; 
	}
	set<int> ans;
	for(auto &i: ma) {
		ans.insert(i.second);
	}
	cout << ans.size() << endl;
}
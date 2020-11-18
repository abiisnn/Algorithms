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
#define MAX 55
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;
int convert(string s) {
	stringstream aux(s);
	int n = 0;
	aux >> n;
	return n;
}
int main() {
	optimizar_io

	map<string, int> m = {
		{"hole in one", 1},
		{"condor", 4},
		{"albatross", 3},
		{"eagle", 2},
		{"birdie", 1},
		{"par", 0},
		{"bogey", -1},
		{"double bogey", -2},
		{"triple bogey", -3}
	};

	int suma = 0;
	vector<int> h(18);
	fore(i, 0, 18) {
		cin >> h[i];
		suma += h[i];
	}
	std::cin.ignore(); 
	vector<string> words(18);
	fore(i, 0, 18) {
		getline(cin, words[i]);
	}

	cout << "suma: " << endl;
	cout << suma << endl;
	int ans = 0;
	fore(i, 0, 18) {
		if(words[i].compare("hole in one")) {
			ans++;
		} else {
			ans += m[words[i]];
			ans += h[i];	
		}
		cout << words[i] << " " << h[i] << endl;
		cout<< m[words[i]] << endl;
		
	}
	cout << ans << endl;
}
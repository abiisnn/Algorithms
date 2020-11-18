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
#define MAX 3000000
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

vector<string> matrix(5, "");
map<int, int> posi;
void create() {

	matrix[0] = "/--\\ /-|  ---\\ ---\\ |  | /--- /--- ---- /--\\ /--\\";
	matrix[1] = "|  |   |     |    | |  | |    |       / |  | |  |";
	matrix[2] = "|  |   |  /--/ ---| \\--| \\--\\ |--\\   /  |--| \\--|";
	matrix[3] = "|  |   |  |       |    |    | |  |  /   |  |    |";
	matrix[4] = "\\--/  --- \\--- ---/    | ---/ |--/ /    \\--/ \\--/";
	
	posi[0] = 0;
	fore(i, 1, 10) {
		posi[i] = posi[i-1] + 5;
	}
}

void concatenar(string &s, int col, int d) {
	int pos = posi[d];
	for(int i = pos; i < pos+4; i++) {
		s += matrix[col][i];
	}
}
void solve() {
	lli a, b;
	cin >> a >> b;
	lli num = a + b;
	vector<int> dig;
	if(!num) dig.pb(0);
	while(num) {
		dig.push_back(num % 10ll);
		num = num / 10ll;
	}
	reverse(all(dig));
	for(int col = 0; col < 5; col++) {
		string print = "";
		for(int d = 0; d < dig.size(); d++) {
			concatenar(print, col, dig[d]);
			if(d != dig.size()-1) {
				print += " ";
			}
		}
		cout << print << endl;
	}
}

int main() {
	int t;
	cin >> t;
	create();
	while(t--) {
		solve();
	}
}
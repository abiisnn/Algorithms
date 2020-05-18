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

void solve() {
	int q, m;
	char ans, isCorrect;
	cin >> q >> m;
	vector<string> questions(q, "    ");
	fore(i, 0, m) {
		fore(i, 0, q) {
			cin >> ans >> isCorrect;
			questions[i][int(ans-'A')] = isCorrect;
		}
	}
	string aux = "";
	fore(i, 0, questions.size()) {
		char posAns;
		int numF = 0;
		bool flag = false;
		fore(j, 0, questions[i].size()) {
			if(questions[i][j] == ' '){
				posAns = j + 'A';
			}
			if(questions[i][j] == 'F') numF++;
			if(questions[i][j] == 'T') {
				posAns = j + 'A';
				flag = true;
				break;
			}
		}
		if(flag) aux += posAns;
		else {
			if(numF == 3) aux += posAns;
			else aux += "?";
		}
	}
	for(int i = 0; i < aux.size(); i++) {
		cout << aux[i];
		if(i != aux.size()-1) cout << " ";
	}
}

int main() {
	optimizar_io
	int t;
	cin >> t;
	int i = t;
	int j = 0;
	while(t--) {
		solve();
		if(j != i-1) cout << endl; 
		j++;
	}
}
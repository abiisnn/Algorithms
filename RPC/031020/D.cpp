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
#define MAX 200
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

bool isLowerCase(char s) {
	return (s >= 'a' && s <= 'z');
}
bool isLetter(char s) {
	return (s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z');
}
int convert(string s) {
	stringstream aux(s);
	int n = 0;
	aux >> n;
	return n;
}

bool checkSubmitted(string name, string s) {
	set<string> extension = {".c", ".cpp", ".java", ".py"};
	string ext = "";
	int i = s.size()-1;
	while(i >= 0 && s[i] != '.') {
		ext.pb((s[i]));  
		i--;
	}
	if(i >= 0 && s[i] == '.') ext.pb('.');
	i--;
	string sub = "";
	while(i >= 0) {
		sub.pb((s[i]));
		i--;
	}
	reverse(all(sub));
	reverse(all(ext));
	if(extension.count(ext) > 0 && name.compare(sub) == 0) return true;
	return false;
}
bool check(vector<string> &correct, vector<string> &output) {
	if(output.size() != correct.size()) return false; 
	fore(i, 0, correct.size()) {
		if(correct[i].size() != output[i].size()) return false;
		fore(j, 0, correct[i].size()) {
			if(correct[i][j] != output[i][j]) return false;
		}
	}
	return true;
}
void updateRDE(string &s, int &r, int &d, int &e) {
	string R = "", D = "", E = "";
	int i = 0; 
	while(i < s.size() && s[i] != ' ') {
		R.pb(s[i]);
		i++;
	}
	r = convert(R);
	i++;
	while(i < s.size() && s[i] != ' ') {
		D.pb(s[i]);
		i++;
	}
	d = convert(D);
	i++;
	while(i < s.size()) {
		E.pb(s[i]);
		i++;
	}
	e = convert(E);
}
int main() {
	optimizar_io
	string filename, submittedFile; 
	string rde, csize, osize;
	getline(cin, filename);
	getline(cin, submittedFile);
	int r, d, e;
	getline(cin, rde);
	updateRDE(rde, r, d, e);
	getline(cin, csize);
	int c = convert(csize);
	vector<string> correct(c);
	fore(i, 0, c) getline(cin, correct[i]);
	getline(cin, osize);
	int o = convert(osize);	
	vector<string> output(o);
	fore(i, 0, o) getline(cin, output[i]);

	bool validSub = checkSubmitted(filename, submittedFile);
	bool areEquals = check(correct, output);
	
	if(!validSub) {
		cout << "Compile Error";
	} else if(r != 0) {
		cout << "Run-Time Error";
	} else if(e > d) {
		cout << "Time Limit Exceeded";
	} else if(!areEquals) {
		cout << "Wrong Answer";
	} else cout << "Correct";
	cout << endl;
}
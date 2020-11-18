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
#define MAX 200005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

int main() {
	optimizar_io
	string s;
	vector<string> text;
	while(getline(cin, s), s != "#") {
		text.pb(s);
	}
	int size = 36, maxi = 0;
	fore(i, 0, text.size()) {
		maxi = std::max(maxi, (int)text[i].size());
	}
	if(maxi < size) size = maxi;
	vector<vector<char>> matrix(size, vector<char>(text.size(), ' '));

	for(int i = 0; i < text.size(); i++) {
		int k = 0;
		for(int j = 0; j < std::min(size, (int)text[i].size()); j++) {
			matrix[j][i] = text[i][j];
		}
	}
	string rayas(text.size() *  2 + 1, '-');
	cout << rayas << endl;
	for(int i = 0; i < size; i++) {
		cout << "|";
		for(int j = 0; j < text.size(); j++) {
			cout << matrix[i][j] << "|";
		} cout << endl;
	}
	cout << rayas << endl;
}
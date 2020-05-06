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

int main() {
	optimizar_io
	string text, header;
	getline(cin, text);
	getline(cin, header);

	map<char, int> bucketText;
	map<char, int> bucketHeader;

	fore(i, 0, text.size())  bucketText[text[i]]++;
	fore(i, 0, header.size()) bucketHeader[header[i]]++;
	bool ans = true;
	for(auto &i: bucketHeader) {
		if(i.fi != ' ') {
			if(bucketText[i.fi] < i.se) ans = false;
		}
	}
	if(ans) cout << "YES";
	else cout << "NO";
	cout << endl;
}
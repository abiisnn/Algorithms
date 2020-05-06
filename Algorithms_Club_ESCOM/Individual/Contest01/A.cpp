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
// #define MAX 100005
typedef long long int lli;
typedef long double ld;
const double PI = acos(-1.0);
ld eps = 1e-9;

// MAX = 2 * |str| + 5
#define MAX 100005
vector<int> bucket(MAX);
string transform(string str) {
	string newS((2 * str.size()) + 3, '#');
	newS[0] = '$';
	for(int i = 2, j = 0; i < newS.size(); i+=2, j++) newS[i] = str[j];
	newS[newS.size()-1] = '@';
	return newS;
}
void manacher(string s) {
	s = transform(s);
	int C = 0, R = 0;
	fore(i, 1, s.size()-1) {
		int mirr = 2 * C - i;
		if(i < R) bucket[i] = min(R-i, bucket[mirr]);
		while(s[i + (1 + bucket[i])] == s[i - (1 + bucket[i])]) 
			bucket[i]++;
		if(i + bucket[i] > R) {
			C = i;
			R = i + bucket[i];
		}
	}
}

int main() {
	optimizar_io
	int n;
	string s; 
	cin >> n >> s;
	manacher(s);	
	sort(bucket.begin(), bucket.end());
	int greater = bucket[bucket.size()-1]; 
	int cont = 0;
	for(auto &i: bucket) {
		if(i == greater) cont++;
	}
	cout << greater << endl;
	cout << cont << endl;
}
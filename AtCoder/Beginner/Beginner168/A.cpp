#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
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
	string s; 
	cin >> s;
	int n = s.size()-1;
	if(s[n] == '2' or s[n] == '4' or s[n] == '5' or s[n] == '7' or s[n] == '9') cout << "hon" << endl;
	else if(s[n] == '3') cout << "bon" << endl;
	else cout << "pon" << endl;
}
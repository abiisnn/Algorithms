// https://codeforces.com/problemset/problem/112/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

char toLower(char a){
	if(a < 97) a += 32; 
	return a;
}

int main() {
	optimizar_io
	string a, b;
	bool A, B;
	cin >> a >> b;

	A = true, B = true;
	fore(i, 0, a.size()) {
		a[i] = toLower(a[i]);
		b[i] = toLower(b[i]);
		if(a[i] < b[i]) {
			A = false;
			break;
		}
		else if(b[i] < a[i]) {
			B = false;
			break;
		}
	}
	if(A && B) cout << "0" << endl;
	else if(!A) cout << "-1" << endl;
	else cout << "1" << endl;
}
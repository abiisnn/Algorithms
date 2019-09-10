#include <bits/stdc++.h>
using namespace std;
#define forn(i,a,n) for(int i =0; i < n; i++)
#define endl '\n'
vector<string> c;
void fillc(){
	c.resize(10);
	c[0] = "0";
	c[1] = "0 1 0";
	c[2] = "0 1 2 1 0";
	c[3] = "0 1 2 3 2 1 0";
	c[4] = "0 1 2 3 4 3 2 1 0";
	c[5] = "0 1 2 3 4 5 4 3 2 1 0";
	c[6] = "0 1 2 3 4 5 6 5 4 3 2 1 0";
	c[7] = "0 1 2 3 4 5 6 7 6 5 4 3 2 1 0";
	c[8] = "0 1 2 3 4 5 6 7 8 7 6 5 4 3 2 1 0";
	c[9] = "0 1 2 3 4 5 6 7 8 9 8 7 6 5 4 3 2 1 0";
}
int main(){
	int n;
	cin >> n;
	fillc();
	for(int i =0; i <= n; i++){
		forn(j,0,2*(n-i)) cout << " ";
		cout << c[i];
		cout << endl;
	}
	for(int i =n-1; i >= 0; i--){	
		forn(j,0,2*(n-i)) cout << " ";
		cout << c[i];
		cout << endl;
	}
	return 0;
}
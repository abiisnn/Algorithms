// https://codeforces.com/group/jbdVtsXBjp/contest/259854/problem/B
#include<bits/stdc++.h>
#define MAX 12
using namespace std;
typedef long long int lli;

double f[MAX];
double powN[MAX];
void precalcular() {
	f[0] = 1;
	f[1] = 1;
	for(int i = 2; i < MAX; i++) {
		f[i] = f[i - 1] * i;
	}

	powN[0] = 1;
	for(int i = 1; i < MAX; i++) {
		powN[i] = powN[i -1] * 2;
	}  
}

int main() {
	string original, drunken;
	int plox, less, spaces;
	cin >> original >> drunken;

	plox = 0; less = 0, spaces = 0;
	for(int i = 0; i < original.size(); i++) {
		if(original[i] == '+') plox++;
		else less++; 
	}
	for(int i = 0; i < drunken.size(); i++) {
		if(drunken[i] == '+') plox--;
		else if(drunken[i] == '-') less--;
		else spaces++;
	}
	precalcular();
	double ans = 0;
	if((plox == 0) && (less == 0)) ans = 1;
	else if((plox > spaces) or (less > spaces)) ans = 0;
	else if((plox + less) > spaces) ans = 0;
	else {
		ans = (f[spaces] / (f[plox] * f[less])) / powN[spaces];
	}
	cout << fixed << showpoint;
	cout << setprecision(10) << ans << endl;

	return 0;
}
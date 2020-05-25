#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

vector<string> patron(5);
void crearArreglo() {
	patron[0] = "0";
	patron[1] = "0 1 0";
	patron[2] = "0 1 2 1 0";
	patron[3] = "0 1 2 3 2 1 0"; 
	patron[4] = "0 1 2 3 4 3 2 1 0";
	patron[5] = "0 1 2 3 4 5 4 3 2 1 0";
}
int main() {
	int n; cin >> n;
	crearArreglo();
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j < (n-i)*2; j++) cout << " "; 
		cout << patron[i] << endl;
	}
	for(int i = n-1; i >= 0; i--) {
		for(int j = 0; j < (n-i)*2; j++) cout << " "; 
		cout << patron[i];
		if(i != 0) cout << endl;
	}
}
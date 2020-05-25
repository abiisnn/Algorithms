#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

int main() {
	int n; cin >> n;
	vector<lli> lugares(n);
	lli chico = 10000000000; 
	for(int i = 0; i < n; i++) {
		cin >> lugares[i];
		if(lugares[i] < chico) chico = lugares[i];
	}
	int pos = 0, cont = 0;
	for(int i = 0; i < n; i++) {
		if(lugares[i] == chico) {
			pos = i;
			cont++;
		}
	}
	if(cont > 1) cout << "Still Rozdil" << endl;
	else cout << pos + 1 << endl;
}
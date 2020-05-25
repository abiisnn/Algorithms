#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

int main() {
	int n, t; cin >> t;
	while(t--) {
		cin >> n;
		vector<int> v(n);
		int numeroGrande = 0;
		for(int i = 0; i < n; i++){
			cin >> v[i];	
			if(v[i] > numeroGrande) 
				numeroGrande = v[i];
		}
		bool flag = true; 
		for(int i = 0; i < n; i++) {
			int diferencia = numeroGrande - v[i];
			if(diferencia & 1) { // si diferencia es impar
				flag = false;
				break;
			} // if(diferencia % 2 == 0) par
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
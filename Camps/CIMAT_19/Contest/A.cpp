#include<bits/stdc++.h>
using namespace std;
#define endl '\n'

int isMult(int num, vector<int> posibles) {
	for(int i = 0; i < posibles.size(); i++) {
		if((num == 1) && (posibles[i] == 1)) return 1;
		if(posibles[i] != 1)
			if(num % posibles[i] == 0) 
				return 0;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int tc, n, m, aux, resultPi;
	cin >> tc;
	while(tc--) {
		// Pilas, movimientos
		cin >> n >> m;
		//set<int> M;
		vector<int> M(m, 0);
		vector<int> N(n, 0);
		vector<int> dp(100005, 0);
		for(int i = 0; i < m; i++) {
			cin >> M[i];
			dp[M[j]] = 1;
		} 
		for(int i = 0; i < n; i++) 
			cin >> N[i];
		sort(N.begin(), N.end());
		// Hacer DP de la más grande:
		int max = N[N.size()-1];
		for(int i = 1; i < max; i++) {
			
		}
		// Checar cada una de las pilas:
		aux = 0;
		for(int i = 0; i < n; i++) {
			//cout << "Tam pila: " << N[i] << endl;
			resultPi = isMult(N[i], M);
			// cout << "resultPi: " << resultPi << endl;
			aux ^= resultPi;
		}
		if(aux) cout << "Gana el primer jugador." << endl;
		else cout << "Gana el segundo jugador." << endl;
	}	
}
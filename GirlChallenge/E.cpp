#include<bits/stdc++.h>
#define MAX 1000005
typedef long long int lli;
using namespace std;

int main() {
	int n; cin >> n;
	vector<int> soldados(n);
	for(int i = 0; i < n; i++) cin >> soldados[i];

	int menor = 10000, indexA, indexB;
	for(int i = 0; i < n-1; i++) {
		int dis = abs(soldados[i] - soldados[i+1]);
		if(dis < menor) {
			menor = dis;
			indexA = i;
			indexB = i + 1;
		}
	}
	int dis = abs(soldados[0] - soldados[soldados.size()-1]);
	if(dis < menor) {
		menor = dis;
		indexA = 0;
		indexB = soldados.size()-1;
	}
	cout << indexA+1 << " " << indexB+1 << endl;
}
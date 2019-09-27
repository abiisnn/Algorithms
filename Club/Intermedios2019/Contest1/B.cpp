#include<bits/stdc++.h>
using namespace std;
int main() {
	int n, cont;
	cin >> n;
	vector<int> v(n, 0);
	vector<int> aux(n, 0);

	for(int i = 0; i < n; i++) 
		cin >> v[i];

	for(int i = 0; i < n; i++) 
		aux[i] = v[i];
	
	sort(aux.begin(), aux.end());
	cont = 0; 
	for(int i = 0; i < n; i++) {
		if(v[i] != aux[i]) cont++;
	}
	if(cont <= 2) cout << "YES" << endl;
	else cout << "NO" << endl;
}
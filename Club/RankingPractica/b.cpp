#include<bits/stdc++.h> 
using namespace std; 

int main() {
	int casos; cin >> casos;
	while(casos--) {
		int n, k;
		cin >> n >> k;
		vector<int> v;		
		while(n--) {
			vector <int> productos(3);
			for(int i = 0; i < 3; i++) {
				cin >> productos[i];
			}		
			sort(productos.begin(), productos.end());
			v.push_back(productos[0]);
			v.push_back(productos[1]);
		}
		sort(v.begin(), v.end());
		int costo = 0;		
		for(int j = 0; j < k; j++) {
				costo += v[j]; 	
		}
		cout << costo << endl;
	}
}

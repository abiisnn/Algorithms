#include<bits/stdc++.h>
using namespace std;

int busquedaBinaria(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(v[mid] == target) return mid; // ENCONTRAMOS
		if(v[mid] < target) l = mid + 1; // Movemos derecha
		else r = mid - 1; // Movemos a la izquierda
	}
	return -1;
}

int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	int q; cin >> q;
	int num;
	for(int i = 0; i < q; i++) {
		cin >> num;
		int is = busquedaBinaria(v, num);
		if(is != -1) {
			cout << "Yes en la posicion" << is << endl;
		} else cout << "No" << endl;
	}
}
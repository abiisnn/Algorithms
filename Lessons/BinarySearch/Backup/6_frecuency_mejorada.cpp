#include<bits/stdc++.h>
using namespace std;

int upperBound(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;
	while(l <= r) {
		int m = l + (r - l) / 2;
		if(v[m] < target) l = m + 1; 
		else if(v[m] > target) r = m - 1;
		else l = m + 1;
	}
	return l;
}
int lowerBound(vector<int> &v, int target) {
	int l = 0, r = v.size() - 1;
	while(l <= r) {
		int m = l + (r - l) / 2;
		if(v[m] < target) l = m + 1; 
		else if(v[m] > target) r = m - 1;
		else r = m - 1;
	}
	return l;
}

int main() {
	// Sacar la frecuencia de un número
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) cin >> v[i];

	int number; cin >> number;
	cout << upperBound(v, number) - lowerBound(v, number);
}
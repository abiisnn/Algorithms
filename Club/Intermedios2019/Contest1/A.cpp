#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	long long int r = 0, sum, j, p;
	cin >> n;

	vector<long long int> v(n, 0);
	for(int i = 0; i < n; i++) 
		cin >> v[i];
	sort(v.begin(), v.end());

	j = n-1;
	for(int i = 0; i < (n/2); i++) {
		sum = v[i] + v[j];
		r += (sum * sum);
		j--; 
	}
	cout << r << endl;
}
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main() {
	int n;
	cin >> n;
	vector<int> arr(n, 0);
	for(int i = 0; i < n; i++) cin >> arr[i];

	bool inc = false, dec = false;
	for(int i = 0; i < n - 1; i++) {
		if(arr[i + 1] > arr[i]) inc = true;
		if(arr[i + 1] < arr[i]) dec = true; 
	}
	if(!(inc & dec)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}
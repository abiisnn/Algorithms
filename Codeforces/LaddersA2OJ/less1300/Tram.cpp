// https://codeforces.com/problemset/problem/116/A
#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'

int main() {
	int i, t, a, b, max, counter; 
	cin >> t;
	counter = 0, max = 0;
	fore(i, 0, t) {
		cin >> a >> b;
		counter -= a;
		counter += b;
		if(counter > max) max = counter;
	}
	cout << max << endl;
	return 0;
}
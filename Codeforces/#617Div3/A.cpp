// https://codeforces.com/contest/1296/problem/A
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
	int t, n, num, odd, even;
	cin >> t;
	while(t--) {
		cin >> n;
		odd = 0, even = 0;
		fore(i, 0, n) {
			cin >> num;
			if(num & 1) odd++;
			else even++;
		}
		if((odd == 0) || ((even == 0) && (odd % 2 == 0))) 
			cout << "NO" << endl;	
		else 
			cout << "YES" << endl;
	}
}
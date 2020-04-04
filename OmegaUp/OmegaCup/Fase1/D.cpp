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
typedef long long int lli;
typedef unsigned long long int ulli;

int main() {
	optimizar_io
	ulli n;
	cin >> n;
	vector<ulli> fibo(230, 0);
	fibo[0] = 0, fibo[1] = 1, fibo[2] = 1;
	fore(i, 2, 230) {
		fibo[i] = fibo[i-1] + fibo[i-2];
	} 
	int ans = -1;
	fore(i, 0, fibo.size()) {
		if(fibo[i] == n) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;
}
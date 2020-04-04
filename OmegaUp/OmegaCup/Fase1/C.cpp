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

int main() {
	optimizar_io
	int n;
	vector<lli> fibo(30, 0);
	set<int> fiboNum;
	fibo[0] = 0, fibo[1] = 1, fibo[2] = 1;
	fore(i, 2, 25) {
		fibo[i] = fibo[i-1] + fibo[i-2];
		fiboNum.insert(fibo[i]);
	}
	cin >> n;
	fore(i, 3, n) {
		if(fiboNum.count(i)) continue;
		cout << i << " "; 
	}	
}
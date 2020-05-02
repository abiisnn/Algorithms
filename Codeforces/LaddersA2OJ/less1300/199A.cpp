// https://codeforces.com/contest/199/problem/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 50
typedef long long int lli;

vector<lli> fibo;
void calculateFibo() {
	fibo[0] = 0; fibo[1] = 1; 
 	for(int i = 2; i < MAX; i++) fibo[i] = fibo[i - 1] + fibo[i - 2];
}

int binarySearch(lli x) { 
    int l = 0, r = fibo.size() - 1;
    while (l <= r) { 
        int m = l + (r - l) / 2; 
		if (fibo[m] == x) return m; 
        if (fibo[m] < x) l = m + 1; 
        else r = m - 1; 
    } 
    return -1; 
} 

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	lli n; cin >> n;
	fibo.assign(MAX, 0);
	calculateFibo();
	if(n == 0) cout << "0 0 0" << endl;
	else if(n == 1) cout << "0 0 1" << endl;
	else if(n == 2) cout << "0 1 1" << endl;
	else {
		int index = binarySearch(n);
		cout <<	fibo[index - 1]  << " " << fibo[index - 3] << " " << fibo[index - 4] << endl;
	}
}
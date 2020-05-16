// https://codeforces.com/contest/1294/problem/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t;
	lli a, b, c, n;
	cin >> t;
	while(t--) {
		vector<lli> numbers(3, 0);
		for(int i = 0; i < 3; i++) cin >> numbers[i];
		cin >> n;
		sort(numbers.begin(), numbers.end());
		lli max = numbers[numbers.size() - 1];
		lli cont = 0;
		for(int i  = 0; i < 3; i++) cont += max - numbers[i]; 
		n -= cont;
		if(n == 0) cout << "YES" << endl;
		else if(n < 0) cout << "NO" << endl;
		else if((n % 3) == 0) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
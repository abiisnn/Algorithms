// https://codeforces.com/problemset/problem/200/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n;
	double result, aux;
	cin >> n;
	result = 0;
	for(int i = 0; i < n; i++) {
		cin >> aux;
		result += aux;
	}
	result /= n;
	cout << std::setprecision(10) << fixed;
	cout << result << endl;
}
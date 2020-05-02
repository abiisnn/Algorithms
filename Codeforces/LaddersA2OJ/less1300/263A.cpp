// https://codeforces.com/problemset/problem/69/A
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int number, x, y;
	for(int i = 0; i < 5; i++) {
		for(int j = 0; j < 5; j++) {
			cin >> number;
			if(number) { 
				x = i, y = j;
				break;
			} 
		}
	}
	cout <<  max(2, x) - min(2, x) + max(2, y) - min(2, y);
}
// https://codeforces.com/problemset/problem/266/B
#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define MAX 10000005
typedef long long int lli;
 
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, moves;
	string Q;
	cin >> n >> moves >> Q;
 
	for(int i = 0; i < moves; i++) {
		for(int j = 0; j < Q.size(); j++) {
			if(Q[j] == 'B') {
				if(Q[j + 1] == 'G') {
					Q[j] = 'G';
					Q[j + 1] = 'B';
					j++;
				}
			}
		}
	}
	cout << Q << endl;
}
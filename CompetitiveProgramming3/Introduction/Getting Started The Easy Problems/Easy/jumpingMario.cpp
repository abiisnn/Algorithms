// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2864
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc , n, number, first;
	int high, low;
	int i, j;

	j = 0;
	cin >> tc;
	while(tc) {
		j++;
		cin >> n;
		high = 0; low = 0;
		cin >> first;
		for(i = 0; i < n - 1; i++) {
			cin >> number;
			if(number > first) 
				high++;
			else if(number < first)
				low++;
			first = number;
		}
		cout << "Case " << j << ": " << high << " " << low << endl;
		tc--;
	}
}
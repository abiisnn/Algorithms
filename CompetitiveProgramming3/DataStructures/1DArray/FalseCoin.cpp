// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=606&mosmsg=Submission+received+with+ID+23729800
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc;
	int i, j, n;
	int N, K, P;
	char c;
	cin >> tc;
	while(tc--) {
		cin >> N >> K;
		vector<int> v(N+1, 0);
		for(i = 0; i < K; i++) {
			cin >> P;
			vector<int> number;
			for(j = 0; j < 2*P; j++) {
				cin >> n;
				number.push_back(n);
			} 
			cin >> c;
			if(c == 61) {
				for(j = 0; j < 2*P; j++) 
					v[number[j]] = 1;
			}
		}
		// Counter
		int counter = 0;
		for(i = 1; i <= N; i++) {
			if(v[i] == 0) {
				counter++;
				n = i;
			}
		}
		if(counter == 1) 
			cout << n << endl;
		else
			cout << "0" << endl;
		if(tc != 0)
			cout << endl;
	}
}
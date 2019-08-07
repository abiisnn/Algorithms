// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=623&page=show_problem&problem=2315
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, i, j;
	int K, M, number;
	char c; 
	string line;
	cin >> tc;
	while(tc--) {
		cin >> K;
		vector<pair<int, int>> v;
		vector<int> ascii(257, 0);
		for(i = 0; i < K; i++) {
			cin >> c >> number;
			v.push_back(make_pair(c, number));
		}
		cin >> M; cin.ignore();
	    for(i = 0; i < M; i++) {
	    	getline(cin, line);
	    	for(j = 0; j <= line.length(); j++)
	    		ascii[line[j]]++;
	    	cout << endl;
	    }
	    double amount = 0, aux = 0;
	    for(i = 0; i < K; i++) {
	    	aux = v[i].first;
	    	aux = ascii[aux];
	    	amount += (aux * v[i].second); 
	    }
	    amount /= 100; 
	    printf("%.2lf$", amount);
	    cout << endl;
	}
}
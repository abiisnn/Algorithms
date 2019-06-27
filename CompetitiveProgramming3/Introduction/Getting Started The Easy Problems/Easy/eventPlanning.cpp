// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=2595
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef long long ll;

int main() {
	int participants, budget, hotel, week;
	int payHotel, beds, count;
	int i, j;
	
	while(cin >> participants) {
		vector<int> v;
		cin >> budget >> hotel >> week;
		for(i = 0; i < hotel; i++) {
			cin >> payHotel;
			for(j = 0; j < week; j++) {
				cin >> beds;
				if(beds >= participants) {
					count = participants * payHotel;
					if(count <= budget) {
						v.push_back(count);
					} 
				}
			}
		}
		if(v.size() > 0) {
			sort(v.begin(), v.end());
			cout << v[0] << endl;
		}
		else {
			cout << "stay home" << endl;
		}
	}
}
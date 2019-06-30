// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3947
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int tc, inst, i, number;
	int pos, count;
	char c;
	string word;	

	cin >> tc;
	while(tc) {
		cin >> inst;
		count = 0;
		vector<char> v;
		for(i = 0; i < inst; i++) {
			cin >> word;
			if(!word.compare("LEFT")) {
				v.push_back(word.at(0));
				count--;
			}
			else if(!word.compare("RIGHT")) {
				v.push_back(word.at(0));
				count++;
			}
			else {
				cin >> word >> pos;
				c = v[pos - 1];
				v.push_back(c);
				if(c == 76)
					count--;
				else
					count++;
			}
		}
		cout << count << endl;
		tc--;
	}
}
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3166*
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

vector<pair<int, string>> v(10);

int maxElement() {
	int before, max, num;
	max = 0;
	for(int i = 0; i < 10; i++) {
		num = v[i].first;
		if(num > max) 
			max = num;
	}
	return max;
}
void check(int number) {
	int i, aux;
	for(i = 0; i < 10; i++) {
		aux = v[i].first;
		if(number == aux) 
			cout << v[i].second << endl;
	}
}

int main() {
	string url;
	int tc, n;
	int i, caseN, max;
	
	caseN = 0;
	cin >> tc;
	while(tc) {
		caseN++;
		for(i = 0; i < 10; i++) {
			cin >> url >> n;
			v[i] = make_pair(n, url); 
		}
		cout << "Case #" << caseN << ":" << endl;
		max = maxElement();
		check(max);
		tc--;
	}
}
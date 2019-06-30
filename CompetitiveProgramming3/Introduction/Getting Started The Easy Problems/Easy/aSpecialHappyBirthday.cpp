// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=608&page=show_problem&problem=3999
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int techo(int a, int b) {
	if((a >= 0 && b >0) || (a < 0 && b < 0)) {
		if(a % b == 0) return a / b;
		else return a / b + 1;
	} else {
		return a / b;
	}
}
int main() {
	int tc, i, j, k, n;
	string person;
	vector<string> name;
	vector<string> song = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

	cin >> n;
	for(i = 0; i < n; i++) {
		cin >> person;
		name.push_back(person);
	}
	k = 0;
	for(i = 0; i < techo(n, 16); i++) {
		for(j = 0; j < song.size(); j++) {
			k %= name.size();
			cout << name[k] << ": " << song[j] << endl; 
			k++;
		}
	}
}
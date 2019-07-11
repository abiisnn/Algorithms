// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=1082
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	int n, p, r;
	int i, j;
	double d;
	string req, word;

	while(1) {
		cin >> n >> p;
		cin.ignore();
		cout << n << " " << p << endl;
		if((n == 0) && (p == 0)) 
			break;
		unordered_map<string, int> words;
		vector<string> proposal(p+1);
		vector<string> price(p+1);

		for(i = 0; i < n; i++) {
			getline(cin, word);
			words[word] = i;
			cout << words[word] << " ";
			cout << word << endl;
		}	
		cout << endl;
		cout << "---> PROPOSAL: " << endl;
		for(i = 0; i < p; i++) {
			getline(cin, word);
			cin >> d >> r;
			cin.ignore();
			cout << "proposal name: " << word << endl;
			cout << d << " " << r << endl;			
			proposal[i] = word;
			price[i] = d;
			for(j = 0; j < r; j++) {
				getline(cin, word);
				cout << word << " " << words.at(word) << endl;
			}
		}
	}

}
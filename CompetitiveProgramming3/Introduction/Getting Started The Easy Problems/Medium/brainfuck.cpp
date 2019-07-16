// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=3107
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
typedef bitset<8> BYTE;

int main() {
	int tc, pointer;
	int i, j;
	string word;
	cin >> tc;
	cin.ignore();
	for(i = 1; i <= tc; i++) {
		vector<int> v(100, 0);
		getline(cin, word);
		cout << word << endl;
		pointer = 0;
		for(j = 0; j < word.length(); j++) {
			if(word[j] == 43) { // +
				// if(v[pointer] == 0) 
				// 	v[pointer] = 1;
				// else if(v[pointer] == 255)
				// 	v[pointer] = 0;
				// else 
				// 	v[pointer] << 1;
				v[pointer] = 5;
			}
			else if(word[j] == 45) { // -
				// if(v[pointer] == 0)
				// 	v[pointer] = 255;
				// else 
				// 	v[pointer] >> 1;
				v[pointer] = 5;
			}
			else if(word[j] == 60) { // <
				if(pointer == 0) pointer = 99;
				else pointer--;
			}
			else if(word[j] == 62) { // >
				if(pointer == 99) pointer = 0;
				else pointer++;
			}
		}	
		cout << "Case " << i << ": ";
		for(j = 0; j < 12; j++) 
			cout << std::hex << v[j] << " ";
		cout << endl;
		i = 1;
		for(j = 12; j < 100; j++, i++) {
			cout << std::hex << v[j] << " ";
			if(!(i % 15))
				cout << endl;
		}
	}
}
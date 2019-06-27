// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=3402
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main () {
	char tc;
	string word;
	int i = 0;
	cin >> word;
	while(word.compare("#")) {
		i++;
		if(!word.compare("HELLO"))
			cout << "Case " << i << ": ENGLISH" << endl;
		else if(!word.compare("HOLA")) 
			cout << "Case " << i << ": SPANISH" << endl;
		else if(!word.compare("HALLO")) 
			cout << "Case " << i << ": GERMAN" << endl;
		else if(!word.compare("BONJOUR")) 
			cout << "Case " << i << ": FRENCH" << endl;
		else if(!word.compare("CIAO")) 
			cout << "Case " << i << ": ITALIAN" << endl;
		else if(!word.compare("ZDRAVSTVUJTE")) 
			cout << "Case " << i << ": RUSSIAN" << endl;
		else 
			cout << "Case " << i << ": UNKNOWN" << endl;
		cin >> word;
	}
}
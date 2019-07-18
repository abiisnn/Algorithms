#include<bits/stdc++.h>

using namespace std;
string str;
int changeLetter(char a) {
	return a + 32;
}
vector<char> removeSpaces(vector<char> newString) {
	int count = 0;
	for(int i = 0; str[i]; i++) 
		if((str[i] != ' ') && ((str[i] >= 65) && (str[i] <= 90)) || ((str[i] >= 97) && (str[i] <= 122))) {
			if((str[i] >= 65) && (str[i] <= 90))
				str[i] = changeLetter(str[i]);
			newString.push_back(str[i]);
		}
	return newString;
}
int main() {
	int end, k, con;

	while(getline(cin, str), str.compare("DONE")) {
		vector<char> newString;
		newString = removeSpaces(newString);
		if(newString.size() <= 1)
			cout << "You won't be eaten!" << endl;
		else {
			if((newString.size() % 2 ) == 0) end = (newString.size() / 2);
			else end = (newString.size() - 1) / 2;    
			k = newString.size() - 1; con = 0;
			for(int i = 0; i < end; i++, k--) { 
				if(newString[i] != newString[k])
					con++;
			}
			if(con)
				cout << "Uh oh.." << endl;
			else 
				cout << "You won't be eaten!" << endl;
		}
	}	
}
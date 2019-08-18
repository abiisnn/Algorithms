#include<bits/stdc++.h>
using namespace std;
 
char convertLower(char c) {
	if((c >= 65) && (c <= 90)) 
		c += 32;
	return c; 
}
int main(){
	int tc, cont;
	string str1, str2;
	char a, b;
	cin >> tc;
	while(tc--) {
		cin >> str1 >> str2;
		if(str1.length() == str2.length()) {
			if(str1.length() != 0) {
				cont = 0;
				for(int i = 0; i < str1.length(); i++) {
					str1[i] = convertLower(str1[i]); str2[i] = convertLower(str2[i]);
					if(str1[i] == str2[i]) cont++;
					else if((str1[i] == 112) && (str2[i] == 98)) cont++;
					else if((str2[i] == 112) && (str1[i] == 98)) cont++;
					else if((str1[i] == 105) && (str2[i] == 101)) cont++;
					else if((str2[i] == 105) && (str1[i] == 101)) cont++;
				}
				if(cont == str1.length()) cout << "Yes" << endl;
				else cout << "No" << endl;
			} else cout << "Yes" << endl;
		} else cout << "No" << endl;
	}
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	string str;

	while(cin >> str) {
		vector<int> b(7, 0);
		string ans = "";
		int num, ant;
		num = 0; ant = 0;
		for(int i = 0; i < str.length(); i++) {
			// cout << "-----------> Estoy en: " << str[i] << endl; 
			num = 0;
			if((str[i] == 66) || (str[i] == 70) || (str[i] == 80) || (str[i] == 86)) {
				num = 1;
			}
			else if((str[i] == 67) || (str[i] == 71) || (str[i] == 74) || (str[i] == 75) || (str[i] == 81) || (str[i] == 83) || (str[i] == 88) || (str[i] == 90)) {
				num = 2;
			}
			else if((str[i] == 68) || (str[i] == 84)) {
				num = 3;
			}
			else if(str[i] == 76) {
				num = 4;
			}
			else if((str[i] == 77) || (str[i] == 78)) {
				num = 5;
			}
			else if(str[i] == 82) {
				num = 6;
			}
			// cout << "Num is: " << num << endl;
			b[num]++;

			if(num != 0) {
				// cout << "bucket: " << b[num] << endl;
				if((b[num] == 1) && (ant != num) ) {
					std::string cad = std::to_string(num);
					ans += cad;
					// cout << "Ans is: " << ans << endl;
				} 
			}
			ant = num;
		}
		cout << ans << endl;
		str = "";
	}
}
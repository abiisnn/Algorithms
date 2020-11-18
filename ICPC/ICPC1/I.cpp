#include<bits/stdc++.h>
using namespace std;
int main(){
	string pass;
	int n, aux=1;
	cin >> n;
	set<char> exist = {'.', '#', '$', '%', '/', '(', '&', ')'};
	while(n--){
		int tot=0, dig = 0;
		cin >> pass;
		vector<bool> flags(5, false);
		bool consecutive = false;
		for(int i=0; i<pass.length(); i++){
			if(islower(pass[i]))
				flags[0] = true;
			else if(isupper(pass[i]))
				flags[1] = true;
			else if(isdigit(pass[i])) {
				dig++;
			}
			else if(exist.count(pass[i]))
				flags[3] = true;
		}
		flags[4] = pass.length() >= 10;

		bool conse = false;
		for(int i = 0; i < pass.size()-1; i++) {
			if(isdigit(pass[i]) && isdigit(pass[i+1]) && (pass[i] == pass[i+1]+1 || pass[i] == pass[i+1]-1)){
				conse = true;
				break;
			}
		}

		flags[2] = dig > 0 && !conse;
		for(bool carac : flags)
			if(carac) tot++;
		if(tot==5) cout << "Assertion number #" << aux << ": Strong" << endl;
		else if(tot==4) cout << "Assertion number #" << aux << ": Good" << endl;
		else if(tot==3) cout << "Assertion number #" << aux << ": Weak" << endl;
		else cout << "Assertion number #" << aux << ": Rejected" << endl;

		aux++;
	}
}

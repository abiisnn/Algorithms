#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>> n;
	bool soup=false,pancakes=false,check=true;
	string ans;

	while(n--){
		int menu; cin>>menu;
		cin.ignore();
		string rest; getline(cin,rest);
		while(menu--){
			string s;
			getline(cin,s);
			if(s=="pea soup"){
				soup=true;
			}
			else if(s=="pancakes"){
				pancakes=true;
			}
		}
		if(soup && pancakes && check){
			ans = rest; check = false;
		}else{
			soup=false; pancakes=false;
		}
	}

	if(!check)
		cout<<ans<<endl;
	else
		cout<<"Anywhere is fine I guess"<<endl;
	return 0;
}
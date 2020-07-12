#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, w=0, b=0, aux=0, wF=0, bF=0;
	bool flagR=true, flagC=true, flag3=true, flagW=true, flagB=true, flag3F=true;
	char c;
	cin >> n;
	vector<vector<char>> grid;
	for(int i=0; i<n; i++){
		vector<char> v;
		for(int j=0; j<n; j++){
			cin >> c;
			v.push_back(c);
			if(c=='W')
				w++;
			else
				b++;
		}
		if(w!=b)
			flagC = false;
		w = 0;
		b = 0;
		grid.push_back(v);
		
	}

	w = 0;
	b = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grid[i][j] == 'W'){
				flagW = true;
				flagB = false;
				b = 0;
			}else{
				flagB = true;
				flagW = false;
				w = 0;
			}
			if(flagW)
				w++;
			else if(flagB)
				b++;

			if(w>=3 || b>=3){
				flag3 = false;
				break;
			}
		}
		w = 0;
		b = 0;
	}

	flag3F = true;
	w = 0;
	b = 0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(grid[j][i] == 'W'){
				flagW = true;
				flagB = false;
				bF = 0;
				w++;
			}else{
				flagB = true;
				flagW = false;
				wF = 0;
				b++;
			}
			if(flagW)
				wF++;
			else if(flagB)
				bF++;

			if(wF>=3 || bF>=3){
				flag3F = false;
				break;
			}
		}
		if(w != b){
				flagR = false;
				break;
			}
		wF = 0;
		bF = 0;
		w = 0;
		b = 0;
	}

	if(flagC && flagR && flag3 && flag3F){
		cout << "1" << endl;
	}else{
		cout << "0"<< endl;
	}
	return 0;
}
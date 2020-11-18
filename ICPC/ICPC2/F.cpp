#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;

void impPunt(int L, int R, char saca, int GL, int GR){
	if(GL == 2){
		cout<< GL <<" (winner) - "<<GR;
	}else if(GR == 2){
		cout<< GL <<" - "<<GR<< " (winner) ";
	}else{
		if(saca == 'R'){
			cout<<GL<<" ("<<L<<") - "<<GR<<" ("<<R<<"*)";
		}else{
			cout<<GL<<" ("<<L<<"*) - "<<GR<<" ("<<R<<")";
		}
	}cout<<endl;
}

void gana(int &R, int &L, int &GanadosR, int &GanadosL, char &saca){
	if(R == 10){
		GanadosR++;
		R = 0; L = 0;
	}else if(L == 10){
		GanadosL++;
		L = 0; R = 0;
	}else if(L >= 5){
		if(L - R >=2){
			GanadosL++;
			L = 0; R = 0;
		}
	}else if(R >= 5){
		if(R - L >= 2){
			GanadosR++;
			L = 0; R = 0;
		}
	}	
}
int main(){
	string s; char saca;
	cin >> s;

	int L = 0, R = 0, GanadosL = 0, GanadosR = 0;
	
	if(s[0] == 'S'){
		L++; saca = 'L';
	}else if(s[0] == 'R'){
		R++; saca = 'R';
	}

	for(int i = 1; i < s.size(); i++){
		if(s[i] == 'S'){
			if(saca == 'R'){
				R++; saca = 'R';
				gana(R,L,GanadosR,GanadosL,saca);
			}else if(saca == 'L'){
				L++; saca = 'L';
				gana(R,L,GanadosR,GanadosL,saca);
			}
		}else if(s[i] == 'R'){
			if(saca == 'R'){
				L++; saca = 'L';
				gana(R,L,GanadosR,GanadosL,saca);
			}else if(saca == 'L'){
				R++; saca = 'R';
				gana(R,L,GanadosR,GanadosL,saca);
			}
		}else if(s[i] == 'Q'){
			impPunt(L,R,saca,GanadosL,GanadosR);
		}
	}
	return 0;
}
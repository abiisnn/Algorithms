#include <bits/stdc++.h>
using namespace std;

int main(){
	int n; cin>>n;
	string inicio, fin, cambios;
	cin>> inicio >> fin;
	cambios = inicio;
	bool f=1;

	for(int i=0; i<n; i++){
		if(i==0){
			if(cambios[n-1]==fin[i] || cambios[i+1]==fin[i])
				cambios[i] = fin[i];
			else
				f=0;
		}else if(i==n-1){
			if(cambios[0]==fin[i] || cambios[i-1]==fin[i])
				cambios[i] = fin[i];
			else
				f=0;
		}else{
			if(cambios[i-1]==fin[i] || cambios[i+1]==fin[i])
				cambios[i] = fin[i];
			else 
				f=0;
		}
	}
	if(f)
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
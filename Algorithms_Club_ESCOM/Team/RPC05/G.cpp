#include <bits/stdc++.h>
using namespace std;

int main(){
	vector <bool> v(10000,0);
	int inicio=8,sobran=8, i=2019;
	v[2018]=1;

	while(i<10001){
		int temp = 26 - (sobran+12);
		if(temp<=12){
			v[i+1]=1;
			i+=2;
			inicio = temp;
			sobran = 12 - inicio;
		}else{
			v[i+2]=1;
			i+=3;
			inicio = temp -12;
			sobran = 12 - inicio;
		}
	}
	int n; cin>>n;

	if(v[n])
		cout<<"yes"<<endl;
	else
		cout<<"no"<<endl;
	return 0;
}
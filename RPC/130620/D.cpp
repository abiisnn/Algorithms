#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;
typedef long long int lli;

int main(){
	lli A, B,ans=0; cin >> A >> B;

	if(A<B){ //A menor que B
		ans = B-A;
	}else{
		while(A!=B){
			if(A&1 && A>B){//A es impar y es mayor que B
				A+=1; ans++; //Vuelvo A par
			}else if(A>B){//A ya es par pero es mayor que B
				A = A/2; ans++;
			}else if(A<B){// A ya es menor que B pero aún no es B
				A++; ans++;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
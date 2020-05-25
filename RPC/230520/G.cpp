#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;
typedef long long int lli;

int main(){
	int n, m; cin >> n >> m;
	vector <int> grams(m,0);
	vector <int> first(m,0);
	vector <int> second(m,0);

	for(int i=0; i<m; i++){
		cin >> first[i] >> second [i] >> grams[i];
	}
	if(n&1)
		cout<<"impossible"<<endl;
	else{
		int ans=10000000; bool f1=1,f2=0;
		for(int i=0; i<m; i++){
			vector <int> a(n,1); int temp=0;
			a[first[i]-1]=0; a[second[i]-1]=0; temp=grams[i];
			//cout<<first[i]<<","<<second[i]<<" :"<<grams[i]<<endl;
			for(int j=0; j<m; j++){
				if(j!=i){
					if(a[first[j]-1] && a[second[j]-1]){
						//cout<<first[j]<<","<<second[j]<<" :"<<grams[j]<<endl;
						a[first[j]-1] = 0; a[second[j]-1] = 0;
						temp+=grams[j];
					}
				}
			}
			for(int i=0; i<n; i++){
				if(a[i])
					f1=0;
			}
			if(f1){
				ans = min(ans,temp); f2=1;
			}f1=1;
		}
		if(f2)
			cout<<ans<<endl;
		else
			cout<<"impossible"<<endl;
	}
}
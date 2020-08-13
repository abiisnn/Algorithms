#include <bits/stdc++.h>
//#include "/Users/tania/Downloads/stdc++.h"
using namespace std;
typedef long long int lli;

int cuentadif(string a, string b){
	int dif=0;
	for(int i=0; i<a.size(); i++){
		if(a[i]!=b[i])
			dif++;
	}
	return dif;
}
int main(){
	int n,ans=0; cin>>n;
	vector <string> v(n);
	
	for(int i=0; i<n; i++)
		cin>>v[i];

	for(int k=0; k<n; k++){
		set <string> f;
		f.insert(v[k]);
		for(int i=0; i<n; i++){
			if(cuentadif(v[k],v[i])>2 && i!=k){
				f.insert(v[i]);
			}
		}

		for(int i=0; i<n; i++){
			std::set<string>::iterator it; it=f.find(v[i]); //cout<<v[i]<<endl;
			if(it!=f.end() && i!=k){
				for(int j=i+1; j<n; j++){
					if(cuentadif(v[i],v[j])<3)
						f.erase(v[j]);
				}
			}
		}
		int s = f.size();
		//cout<<s<<endl;
		ans=max(ans,s);
	}
	cout<<ans<<endl;
	return 0;
}
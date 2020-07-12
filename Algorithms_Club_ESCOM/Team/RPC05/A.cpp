#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, ans=0; cin>>n;
	vector <int> t(n,0);
	vector <int> d(n,0);

	for(int i=0; i<n; i++){
		cin>>t[i]>>d[i];
	}

	for(int i=0; i<n-1; i++){
		int temp = (d[i+1]-d[i])/(t[i+1]-t[i]);
		ans = max(ans,temp);
	}
	cout<<ans<<endl;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main(){
	int n=0, c=0, volunt=0;
	cin >> n >> c;
	vector <int> weights(n,0);
	vector <int> s(n,0);

	for(int i=0; i<n ; i++)
		cin>>weights[i];
	sort(weights.begin(), weights.end());

	int i=0, j=n-1;
	while(i<n && j>=0){
		if(s[i]==1){
			i++;
			continue;
		}
		else if(s[j]==1){
			j--;
			continue;
		}
		else if(weights[i]+weights[j] <= c ){
			s[i]=1;
			s[j]=1;
			volunt++; j--; i++;
		}
		else if(weights[j] <= c){
			s[j]=1;
			volunt++;
			j--;
		}
	}
	cout<< volunt <<endl;
	return 0;
}
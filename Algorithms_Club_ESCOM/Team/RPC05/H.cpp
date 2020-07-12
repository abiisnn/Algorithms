#include <bits/stdc++.h>
using namespace std; 
int main(){
	bool flag=true;
	int n, tot;
	long long int s;
	cin >> n;
	vector <long long int> sock;
	vector <long long int> aux;

	map <int, int> frequency;

	for(int i=1; i<=(2*n); i++){
		cin >> s;
		if(i <= n){
			sock.push_back(s);
		}else{
			aux.push_back(s);
		}
		frequency[s]++;
	}

	reverse(aux.begin(), aux.end());

	map<int,int>::iterator pos;
	for(pos=frequency.begin(); pos!=frequency.end(); pos++){
		if(pos->second%2 != 0)
			flag = false;
	}

	if(!flag){
		cout << "impossible"<<endl;
	}else{
		tot = n;
		for(int i=0; i<n; i++){
			if(sock[i] == aux[i])
				tot++;
			else
				flag = false;
		}
		if(flag)
			cout << tot<<endl;
		else 
			cout << "impossible"<<endl;
	}
	



	

	return 0;
}
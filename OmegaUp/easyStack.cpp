#include<bits/stdc++.h>
using namespace std;

int main(){
	int t, n, p;
	vector<int> st;
	cin >> t;
	while(t--){
		cin >> p;
		if(p == 1){
			// Este es push
			cin >> n;
			st.push_back(n);
		}
		else if(p == 2){
			// Este es pop
			if(!st.empty())
				st.pop_back();
		}
		else {
			// Este es top
			if(!st.empty())
				cout << st[st.size() -1] << endl;
			else
				cout << "Empty!" << endl;
			
		}
	}
}
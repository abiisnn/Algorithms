#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, q;
	char query;
	cin >> n >> q;
	vector<map<int,int>> preferences(n);

	int i,j,c, maxDiference=0;
	pair<int,int> maxElement;
	bool multipleMax = false;

	while(q--){
		cin >> query;
		if(query == 'R'){
			cin >> i >> j;
			preferences[i][j]++;
			if(preferences[i][j] > maxDiference){
				maxDiference = preferences[i][j];
				maxElement = make_pair(i, j);
				multipleMax = false;
			}else if(preferences[i][j] == maxDiference){
				multipleMax = true;
			}
		}else if(query=='B'){
			if(multipleMax)
				cout << "Multiple" << endl;
			else
				cout << maxElement.first << " " << maxElement.second << endl;
		}else{
			cin >> c;
			if(preferences[c].empty()){
				cout << "No info" << endl;
				continue;
			}
			int maxDif = 0, maxElem;
			bool multiple = false;
			for(auto pos=preferences[c].begin(); pos!=preferences[c].end(); pos++){
				if(pos->second > maxDif){
					maxElem = pos->first;
					maxDif = pos->second;
					multiple = false;
				}else if(pos->second == maxDif){
					multiple = true;
				}
			}
			if(multiple)
				cout << "Multiple" << endl;
			else
				cout << maxElem << endl;
		}
	}
}


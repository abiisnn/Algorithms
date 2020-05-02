#include <bits/stdc++.h>
using namespace std;

int main(){
	int s;
	cin>> s;
	vector < pair<int,int> > slot;

	for(int i=0; i<s; i++){
		int a,b;
		cin>> a >> b;
		slot.push_back(make_pair(a,b));
	}

	int c;
	cin>> c;
	vector < pair<int,int> > coins;

	for(int i=0; i<c; i++){
		int x,y;
		cin>> x >> y;
		coins.push_back(make_pair(x,y));
	}
	int dist=0;

	for(int i=0; i<c; i++){
		for(int j=0; j<s; j++){
			if(coins[i].first <= slot[j].first){
				if(coins[i].second >= slot[j].second){
					dist++;
					break;
				}
			}
			dist++;
		}
	}
	cout<<dist<<endl;
	return 0;
}
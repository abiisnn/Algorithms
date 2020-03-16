#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
//typedef pair<int, int> pairs;

int main() {
	int n, a, b;
	bool is_in;
	set<pair<int, int>> posibles, answer;
	vector<pair<int, int>> v;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		posibles.insert(make_pair(a, b));
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			pair<int, int> sum = make_pair(v[i].first + v[j].first, v[i].second + v[j].second);
			pair<int, int> res = make_pair(v[i].first + v[j].first, v[i].second + v[j].second);
			std::set<pair<int, int>>::iterator itSum = posibles.find(sum);
			std::set<pair<int, int>>::iterator itRes = posibles.find(res);
			if((itSum != posibles.end()) || (itRes != posibles.end())) {
				pair<int, int> aux = make_pair(v[j].first, v[j].second);
				answer.insert(aux);
			}				
		}
	}
	cout << answer.size() << endl;
}
#include<bits/stdc++.h>

using namespace std;

int main() {
	int n, pos, amount, persons;
	int sum;
	string name;

	while(cin >> n) {
		unordered_map<string, int> names;
		vector<int> result(n, 0);
		
		for(int i = 0; i < n; i++) {
			cin >> name;
			names[name] = i;
		}
		for(auto x: names) 
			cout << x.first << " " << x.second << endl;
		for(int i = 0; i < n; i++) {
			cin >> name >> amount >> persons;
			pos = names.at(name);
			sum = -1 * amount;
			result[pos] += sum;
			if(persons != 0) {
				sum = amount / persons; 
				result[pos] += amount - sum;
			}
			for(int j = 0; j < persons; j++) {
				cin >> name;
				pos = names.at(name);
				result[pos] += sum;
			}
		}
	 
		cout << endl;
	}
}
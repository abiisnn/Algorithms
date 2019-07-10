#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, pos, amount, persons;
	int sum, give;
	string name;
	int i = 0;
	while(cin >> n) {
		if(i != 0)
			cout << endl;
		i++;
		unordered_map<string, int> names;
		vector<string> auxNames(n);
		vector<int> result(n, 0);
		
		for(int i = 0; i < n; i++) {
			cin >> name;
			names[name] = i;
			auxNames[i] = name;
		}
		for(int i = 0; i < n; i++) {
			cin >> name >> amount >> persons;
			pos = names.at(name);
			if(persons != 0) 
				result[pos] += (-1 * amount);
			sum = 0; give = 0;
			if(persons != 0) {
			 	give = amount / persons;
			 	sum = give * persons; 
			 	sum = amount - sum;
			 	result[pos] += sum;
			}
			for(int j = 0; j < persons; j++) {
			 	cin >> name;
			 	pos = names.at(name);
			 	result[pos] += give;
			}
		}
 		// showing contents:
 		for(int i = 0; i < n; i++) {
 			cout << auxNames[i] <<  " " << result[i] << endl;
 		}
 	}
  }
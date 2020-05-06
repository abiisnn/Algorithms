#include<bits/stdc++.h>
using namespace std;
using lli = long long int;
#define MAX 9
 
int main() {
	int n;
	int c = 1;
	while(cin >> n, n != 0) {
		string read;
		map<string, int> bucket;
		vector<int> counter(MAX, 0);
		
		int index = 0;
		for(int i = 0; i < n; i++) {
			cin >> read;
			auto search = bucket.find(read);
			if(search == bucket.end()) {
				bucket[read] = index;
				index++;
			} 
			counter[bucket[read]]++;
		}
		sort(counter.begin(), counter.end());
		
		int bolsas = counter[counter.size()-1];
		vector<int> result(bolsas, 0);
		for(int i = 0; i < 9; i++) {
			for(int j = 0; j < counter[i]; j++) {
				result[j]++;
			}
		}
		sort(result.begin(), result.end());
		cout << "Case " << c << ": ";
		for(int i = 0; i < bolsas; i++) {
			if(result[i]) cout << result[i];
		}
		cout << endl;
		c++;
	}
}
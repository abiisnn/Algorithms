#include <bits/stdc++.h>
using namespace std;

int totCombinations(vector<int> divisores, int k){
	return 0;
}

int main(){
	int aux, n, k; cin >> n, k;
	long long int tot=0;
	vector<vector<int>> nums;
	for(int i=1; i<=n; i++){
		vector<int> div;
		for(int j=1; j<=n; j++){
			aux = j;
			if(i%j == 0)
				div.push_back(aux);
		}
		sort(div.begin(), div.end(), greater<int>());
		nums.push_back(div);
	}

	for(int i=1; i<=n; i++){
		vector<int> divOfN = nums[i];
		tot += totCombinations(divOfN, k);
	}

	cout << (totCombinations%1000000007) << endl;


	return 0;
}
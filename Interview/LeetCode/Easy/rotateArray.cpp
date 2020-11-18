#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int> &nums, int k) {
	if(k == 0) {
		return;
	}
	int cont, j, backup, aux, times;
	k %= nums.size();
	for(int i = 0; i < k; i++) {
		backup = nums[i];

		times = floor((nums.size() - i) / k);
		cout << "original Times: " << times << endl;
		if(times <= 0) {
			times = 1;
		} else if(((nums.size() - i) & 1)) {
			times--;
		}
		cout << times << endl;
		for(cont = 0, j = i + k; cont < times; cont++, j += k) {
			aux = nums[j % nums.size()];
			nums[j % nums.size()] = backup;
			backup = aux;
		}
		nums[j % nums.size()] = backup;
		for(int i = 0; i < nums.size(); i++) {
			cout << nums[i] << " ";
		} cout << endl;

	}
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> num(n, 0);
	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}
	rotate(num, k);	

	for(int i = 0; i < n; i++) {
		cout << num[i] << " ";
	} cout << endl;
}
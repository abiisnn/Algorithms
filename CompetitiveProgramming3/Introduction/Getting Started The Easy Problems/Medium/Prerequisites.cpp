// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=3922
#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> c, int l, int r, int x) {
	while(l <= r) {
		int m = l + (r - l) / 2; 
        // Check if x is present at mid 
        if (c[m] == x) 
            return m; 
        // If x greater, ignore left half 
        if (c[m] < x) 
            l = m + 1; 
        // If x is smaller, ignore right half 
        else
            r = m - 1; 
	}
	return -1;
}
int main() {
	int k, m, i, j, acum, total;
	int c, r, number, result;

	while(cin >> k, k != 0) {
		cin >> m;
		vector<int> coursesChosen(k, 0);
		for(i = 0; i < k; i++) {
			cin >> number;
			coursesChosen[i] = number;
		}
		// To make Binary Search
		sort(coursesChosen.begin(), coursesChosen.end());
		total = 0;
		for(i = 0; i < m; i++) {
			cin >> c >> r;
			vector<int> category(c, 0);
			for(j = 0; j < c; j++) {
				cin >> number;
				category[j] = number;
			}
			acum = 0; 
			for(j = 0; j < c; j++) {
				// Search the number category[j]
				result = binarySearch(coursesChosen, 0, k - 1, category[j]);
				if(result != -1)
					acum++;
			}
			if(acum >= r)
				total++;
		}
		if(total >= m) 
			cout << "yes" << endl;
		else 
			cout << "no" << endl;
	}
}
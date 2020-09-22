#include<bits/stdc++.h>
using namespace std;
int gauss(int n) {
    return (n - 2) * (n-1) / 2;
}
int numberOfArithmeticSlices(vector<int> &A) {
    if(A.size() < 3) return 0;
    int lastDif = A[1] - A[0], begin = 0, total = 0;
    for(int i = 1; i < A.size()-1; i++) {
        if(A[i+1] - A[i] != lastDif) {
            if(i - begin + 1 >= 3) {
                total += gauss(i - begin + 1);
            }
            begin = i;
            lastDif = A[i+1] - A[i];
        }
    }
    if(A.size() - begin >= 3) {
        total += gauss(A.size() - begin); 
    }
    return total;
}
int numberOfArithmeticSlices(vector<int> &A) {
    if(A.size() < 3) return 0;
    int begin = 0, total = 0;
    for(int i = 1; i < A.size()-1; i++) {
        if(A[i+1] - A[i] != A[i] - A[i-1]) {
            if(i - begin + 1 >= 3) {
                total += gauss(i - begin + 1);
            }
            begin = i;
        }
    }
    if(A.size() - begin >= 3) {
        total += gauss(A.size() - begin); 
    }
    return total;
}
int numberOfArithmeticSlices(vector<int> &A) {
    if(A.size() < 3) return 0;
    int begin = 0, total = 0;
    for(int i = 1; i < A.size()-1; i++) {
        if(A[i+1] - A[i] != A[i] - A[i-1]) {
            if(i - begin + 1 >= 3) {
                total += ((i - begin - 1) * (i - begin) / 2);
            }
            begin = i;
        }
    }
    if(A.size() - begin >= 3) {
        total += ((A.size() - begin - 2) * (A.size() - begin - 1) / 2); 
    }
    return total;
}
int main() {
	int n; cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) {
		cin >> v[i];
	}
	cout << "num: " << numberOfArithmeticSlices(v) << endl;
}
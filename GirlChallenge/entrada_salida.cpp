#include<bits/stdc++.h> // Library
using namespace std;

// time: O(n), space: constante
bool areEquals(vector<int> &a, vector<int> &b) {
	for(int i = 0; i < int(a.size()); i++) {
		if(a[i] != b[i]) return false;
	}
	return true;
}
bool ascOrdes(vector<int> &array) {
	vector<int> ascending = array, decreasing = array;
	sort(ascending);
	reverse(sort(decreasing));
	
	bool asc = areEquals(array, ascending);
	bool des = areEquals(array, decreasing);

	return (asc or des);
}
bool ascOrdes(vector<int> &array) {
	bool asc = true, des = true;
	// asc = t, des = t
	for(int i = 0; i < int(array.size())-1; i++) {
		if(array[i+1] < array[i]) { // -5 < -2
			asc = false;
		} 
		if(array[i+1] > array[i]) { // -5 > -2
			des = false; // des = f
		}
	}
	// 1 0 
	// 0 1
	// 1 1
	return (asc or des);
}

int main() {
	int a;
	string b;
	float c;
	double d;
	long int e;

	// Read from console
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	cin >> e;
	
	// Print data
	cout << a << '\n';
	cout << b << '\n';
	cout << c << endl; // endl = \n
	cout << d << endl;
	cout << e << endl;
}
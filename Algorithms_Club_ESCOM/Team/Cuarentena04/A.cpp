#include <iostream>
#include <cmath>
using namespace std; 
const double PI = acos(-1.0);
double eps = 1e-6;
 
bool geq(double a, double b){return a-b >= -eps;}
bool ge(double a, double b){return a-b > eps;}

int main(){
	int L, R;
	double P, aux;
	cin >> L >> R >> P;
	if(L == R){
		cout << "Ambidextrous";
	}else if(R > L){
		aux = (P/100.0) * R;
		if(geq(L, aux)){
			cout << "Ambidextrous";
		}else{
			cout << "Right-handed";
		}
	}else{
		aux = (P/100.0) * L;
		if(geq(R, aux)){
			cout << "Ambidextrous";
		}else{
			cout << "Left-handed";
		}
	}
	return 0;
}

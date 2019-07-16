// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=609&page=show_problem&problem=514
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	double H, U, D, F;
	int day;
	double factor;
	double initialHeight, distanceClimbed, heightClimbing, heightSliding;

	while(cin >> H, H) {
		cin >> U >> D >> F;
		factor = (F * U) / 100;
		day = 0; 
		initialHeight = 0;
		heightClimbing = 0;

		while(initialHeight >= 0 && heightClimbing <= H) {
			distanceClimbed = U - (factor * day);
			if(distanceClimbed < 0) 
				distanceClimbed = 0; 
			heightClimbing = initialHeight + distanceClimbed;
			initialHeight = heightClimbing - D; 
			day++;
			// cout <<  day << "\t"  << initialHeight << "\t" << distanceClimbed << "\t" << heightClimbing << "\t" << heightSliding << endl;
		}
		if(initialHeight < 0)
			cout << "failure on day " << day << endl;
		else 
			cout << "success on day " << day << endl;

	}
}
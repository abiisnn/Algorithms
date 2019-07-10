#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
	double H, U, D, F;
	int day, flag;
	double factor;
	double initialHeight, distanceClimbed, heightClimbing, heightSliding;

	cin >> H;
	while(H) {
		cin >> U >> D >> F;
		factor = (F * U) / 100;
		day = 1; flag = 0;
		initialHeight = 0;
		distanceClimbed = U;
		heightClimbing = initialHeight + distanceClimbed;
		heightSliding = heightClimbing - D;
		// cout << "day \t"  << "initialHeight \t" << "distanceClimbed \t" << "heightClimbing \t" << "heightSlidinge" << endl;
		// cout <<  day << "\t"  << initialHeight << "\t" << distanceClimbed << "\t" << heightClimbing << "\t" << heightSliding << endl;

		while(1) {
			day++;
			initialHeight = heightSliding;
			distanceClimbed -= factor;
			heightClimbing = initialHeight + distanceClimbed;
			heightSliding = heightClimbing - D; 
			// cout <<  day << "\t"  << initialHeight << "\t" << distanceClimbed << "\t" << heightClimbing << "\t" << heightSliding << endl;

			if(heightClimbing > H) {
				flag = 1;
				break;
			}
			else if((distanceClimbed < 0) || (heightSliding < 0)) {
				flag = 0;
				break;
			}
		}
		if(flag)
			cout << "success on day " << day << endl;
		else 
			cout << "failure on day " << day << endl;

		cin >> H;
	}
}
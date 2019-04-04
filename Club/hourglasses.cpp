#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int array[6][6];
	int i, j;
	int sum = 0, sumT = 0;
	int auxj = 0, auxi = 0;
	
	for(i = 0; i < 6; i++) 
		for(j = 0; j < 6; j++) 
			cin >> array[i][j];

	for(i = 0; i < 4; i++) {
		for(j = 0; j < 4; j++) {
			auxj = j; auxi = i;
			sum = array[auxi][auxj] + array[auxi][auxj+1] + array[auxi][auxj+2] + array[auxi+1][auxj+1] + array[auxi+2][auxj] + array[auxi+2][auxj+1] + array[auxi+2][auxj+2];
			if((sum > sumT))
				sumT = sum;
			//else((sum < sumT) && sum < 0 && sumT < 0)
		}
	}
	cout << sumT;
	return 0;
}
// https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=607&page=show_problem&problem=1491
#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);

int clockwise(int a, int b) {
	int minN, maxN;

	minN = min(a, b);
	maxN = max(a, b);

	if(minN ==  maxN) 
		return 360;
	else if(b > a) 
		return (maxN - minN) * 9;		
	else 
		return 360 - ((maxN - minN) * 9);	
}

int main() {
	int dial, one, two, three;
	int result;
	
	cin >> dial >> one >> two >> three;
	while(dial || one || two || three) {
		result = 1080;
		result += 360 - clockwise(dial, one);
		result += clockwise(one, two);
		result += 360 - clockwise(two, three);
	
		cout << result << endl;
		cin >> dial >> one >> two >> three;
	}
}
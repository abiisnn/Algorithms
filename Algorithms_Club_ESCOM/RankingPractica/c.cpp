#include <bits/stdc++.h>

using namespace std; 

int main()
{
	int casos; cin >> casos; 
	while(casos--)
	{
		int area; cin >> area; 
		area = area / 6; 
		area = sqrt(area);
		cout << area << endl;  
	}
	
	return 0; 
}
 


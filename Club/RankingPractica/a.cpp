#include<bits/stdc++.h> 
using namespace std; 

int main()
{
	int casos; cin >> casos;
	for(int i = 0; i < casos; i++)
	{
		int problemas; cin >> problemas;
		int contador = 0;  
		for(int j = 0;  j < problemas; j++)
		{
			int n; cin >> n; 
			if(n == 0) contador++;  	
		}	
		cout << problemas - contador << endl;
	}
 

	return 0;
}

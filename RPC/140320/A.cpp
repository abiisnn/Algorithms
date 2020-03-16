#include<bits/stdc++.h>
using namespace std;
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
#define fore(i, a, b) for(int i = a; i < b; i++)
#define fori(i, a, b) for(int i = a; i <= b; i++)
#define pb push_back
#define popb pop_back
#define mk make_pair
#define f first
#define s second
#define endl '\n'
typedef long long int lli;

int main()
{
	int n, d; 
	int total = 0; 
	cin >> n >> d; 
	vector<int> v(n); 

	for(int i = 0; i < n; i++)
	{
		cin >> v[i]; 
		total += v[i]; 
	}

	for(int i = 0; i < n; i++) 
	{
		cout << ((float)d / (float)total) * (float)v[i] << "\n"; 
	}


	return 0; 
}
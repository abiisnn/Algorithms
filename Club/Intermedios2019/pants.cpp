#include<bits/stdc++.h>
using namespace std;
int matrix[405][405];
int visited[405];

void fillMatrix() {
	for(int i = 0; i < 405; i++)
		for(int j = 0; j < 405; j++)
			matrix[i][j] = 0;
}

void fillVisited() {
	for(int i = 0; i < 405; i++) 
		visited[i] = 0;
}
bool dfs(int a, int b, int s) {
	if(a == b) return true;
	visited[a] = 1;
	for(int i = 0; i < s; i++) {
		if((matrix[a][i] == 1) && (visited[i] == 0)) {
			bool result = dfs(i, b, s);
			if(result) {
				return true;			
			}		
		}
	}	
	return false;
}
int main()
{
	string country_bad, are, worse, than, country_good; 	
	int facts, statements; 
	cin >> facts >> statements; 
	map<string, int> ids_countries; 	
	map<string, int>::iterator it; 
	int ide = 0, idA, idB;
	fillMatrix();
	// Read data of NYT
	for(int i = 0; i < facts; i++) {
		cin >> country_bad >> are >> worse >> than >> country_good;
		it = ids_countries.find(country_bad); 
		if(it == ids_countries.end()) {
			ids_countries.insert(pair<string, int>(country_bad, ide));
			ide++; 	
		} 
		it = ids_countries.find(country_good); 
		if(it == ids_countries.end())  {	
			ids_countries.insert(pair<string, int>(country_good, ide)); 
			ide++; 
		}	 
		idA = ids_countries[country_bad];
		idB = ids_countries[country_good];
		matrix[idA][idB] = 1;
	}	
	for(int i = 0; i < statements; i++) {
		cin >> country_bad >> are >> worse >> than >> country_good;
		idA = ids_countries[country_bad];
		idB = ids_countries[country_good];
		fillVisited();
		int si = ids_countries.size();	
		if(dfs(idA, idB, si)) { // True
			cout << "Fact" << endl;
		}
		else {
			fillVisited();
			if(dfs(idB, idA, si)) {
				cout << "Alternative Fact" << endl;
			}
			else cout << "Pants on Fire" << endl;
		}
	}
	return 0; 
}

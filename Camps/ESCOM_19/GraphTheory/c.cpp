#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    string cad;
    int cont = 0;
    cin >> cad;
    
    for(int i = 0; i < cad.length(); i++) {
        if(cad[i] == 97)
            cont++;
    }
    int resta = cad.length() - cont;
    if(resta >= cont) 
        cout << (2 * cont) - 1;
    else 
        cout << cad.length();
 
}
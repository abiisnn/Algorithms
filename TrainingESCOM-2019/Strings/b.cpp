#include<bits/stdc++.h>
 
using namespace std;
 
int main() {
    int tamA, cont;
    int i, j, par;
    
    string cad;
    cin >> cad;
    
    par = 1;
    tamA = cad.length();
    if(tamA & 1) {
        par = 0;
        tamA = (tamA - 1) / 2;
    } 
    else
        tamA = tamA / 2;
    
    cont = 0; j = cad.length() - 1;
    for(i = 0; i < tamA; i++) {
       // cout << cad[i] << " " << cad[j] << endl;
        if(cad[i] != cad[j])
            cont++;
        j--;
    }
    if((par == 1) && (cont < 1))
        cout << "NO" << endl;
    else if((par == 0) && (cont < 1))
        cout << "YES" << endl;
    else if(cont <= 1)
        cout << "YES" << endl;
    else 
        cout << "NO" << endl;
}
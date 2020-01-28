#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int n, cont, res;
    cin >> n;
    vector<int> v(n+1, 0);
    vector<int> cubeta;
    cont = 0;
    for(int i = 1; i <= n; i++) {
        cin >> v[i];
        if(v[i] == i) { 
            cont++;
            cubeta.push_back(v[i]);
        }
    }
    if(cont == 0) cout << "0" << endl;
    else if(cont == 1) {
        int n = cubeta[0];
        cout << "1" << endl;
        cout << cubeta[0] << " ";
        for(int i = 0; i < v.size(); i++) {
            if(n != v[i]) {
                cout << v[i] << endl;
                break;
            }
        }
    }
    else if(cont & 1) {
        int aux, aux2;
        res = ((cont - 1)/2) + 1;
        cout << res << endl;
        for(int i = 0; i < cubeta.size()-1; i+=2)
            cout << cubeta[i] << " " << cubeta[i + 1] << endl;
        cout << cubeta[cubeta.size()-3] << " " << cubeta[cubeta.size()-1] << endl;
        
    }
    else {
        res = cont / 2;
        cout << res << endl;
        for(int i = 0; i < cubeta.size(); i+=2) {
            cout << cubeta[i] << " " << cubeta[i + 1] << endl;
        }
    }
  
}
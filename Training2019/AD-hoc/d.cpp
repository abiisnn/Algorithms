#include<bits/stdc++.h>
#define N 1048586
using namespace std;
typedef long long ll;
  
int main() {
    int n, t, number, tam, i;

    cin >> n >> t;
    
    tam = pow(2, n);
    vector <int> v(tam, 0);

    // Get info
    for(i = 0; i < tam; i++) {
        cin >> number; 
        v[i] = number;
    }
   
    if(t & 1) 
        reverse(v.begin(), v.end());
    
    for(i = 0; i < tam; i++) 
        cout << v[i] << " ";
}
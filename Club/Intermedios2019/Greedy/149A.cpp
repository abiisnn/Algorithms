//https://codeforces.com/contest/149/problem/A
#include<bits/stdc++.h>
using namespace std;
 
int main() {
  int k, aux, sum, cont;
  vector<int> v(12, 0);
  cin >> k;
  for(int i = 0; i < 12; i++) 
    cin >> v[i];
  
  if(k == 0) cout << "0" << endl;
  else {
    sort(v.begin(), v.end());
    aux = 0; sum = 0; cont = 0;
    for(int i = 11; i >= 0; i--) {
      if(v[i] == 0) continue;
      aux = sum + v[i];
      if(aux < k) {
        cont++;
        sum = aux;
      } else {
        cont++;
        sum = aux;
        break;
      }
    }
    if(sum >= k) cout << cont << endl;
    else cout << "-1" << endl;
  }
}
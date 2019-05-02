#include<bits/stdc++.h>
#include<vector>

using namespace std;

int main() {
    int n;
//    vector <int> v(3, 0);
    cin >> n;
    for(int i; i < n; i++) {
      vector<int> v(3, 0);
      for(int j = 0; j < 3; j++) {
         cin >> v[j];
      }
      sort(v.begin(), v.end());
      cout << "Case " <<  i +1 << ": "  << v[1] << endl;
    }
}

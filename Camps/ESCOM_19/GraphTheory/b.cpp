#include<bits/stdc++.h>
 
using namespace std;
#define N 10100
 
vector<int> bolita(N, 0);
vector<int> p(N, 0);
vector<int> result(N, 0);
 
int recorrer(int a) {
    bolita[a]++;
    if(bolita[a] == 2) {
        return a;
    }
    else {
        recorrer(p[a]);
    }
}
void create(int n) { 
    for(int i = 0; i <= n; i++)
        p[i] = 0;
}
void reset(int n) {
    for(int i = 0; i <= n; i++)
        bolita[i] = 0;
}
 
int main() {
    int n, number;
    cin >> n;
    create(n); reset(n);
    for(int i = 1; i <= n; i++) {
        cin >> number;
        p[i] = number;
    }
    
    for(int i = 1; i <=n; i++) {
        result[i] = recorrer(i);
        reset(n);
    }
    for(int i = 1; i <=n; i++) 
        cout << result[i] << " ";
    cout << endl;
}
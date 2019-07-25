#include<bits/stdc++.h> 
using namespace std;
typedef long long ll;
 
ll piso(ll a, ll b) {
    if((a >= 0 && b > 0) || (a < 0 && b < 0)) return a / b;
    else {
        if(a % b == 0) return a / b;
        else return a / b - 1;
    }
}
int main() {
    ll a, b, k;
    ll A, B;
    ll superficie, silla;
    ll res;
    cin >> a >> b >> k;
    
    superficie = a * b; silla = k * k;
    
    // No puedo calcular
    if((a < k) || (b < k)) {
        cout << 0;
    }
    else {
        if(a == k)
            cout << piso(b, k);
        else if(b == k)
            cout << piso(a, k);
        else {
            A = piso(a, k); B = piso(b, k);
            res = (A * 2) + (B * 2) - 4;
            cout << res;    
        }
    }
}

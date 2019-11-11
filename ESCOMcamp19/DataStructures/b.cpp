// It is not working!!!!
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 500009
#define endl '\n'
#define optimizar_io ios_base::sync_with_stdio(0); cin.tie(0);
 
vector<ll> dad(N, 1);
vector<ll> sum(N, 1);
 
ll total = 0;
 
ll findUser(ll u) {
    if(dad[u] == u)
        return u;
    return dad[u] = findUser(dad[u]);
}
void unionUsers(ll u, ll v) {
    ll Rv, Ru;
    Rv = findUser(v); 
    Ru = findUser(u);
    
    if(Rv == Ru) return;
    dad[Ru] = Rv;  
    sum[dad[Rv]]++;

}   
 
void reset(ll n) {
    for(ll i = 0; i <= n; i++) 
            dad[i] = i;
}
 
int main() {
    ll n, m, number, usersInGroup;
    ll i, j, k, first, second, element;
    
    cin >> n >> m;
        
    reset(n);
    
    for(i = 0; i < m; i++) {
        cin >> usersInGroup;
        // Make unions
        if(usersInGroup == 1) 
            cin >> element;
        else {
            vector<ll> group;
            for(j = 0; j < usersInGroup; j++) {
                cin >> element;
                group.push_back(element);
            }
            for(j = 0; j < usersInGroup; j++) {
                first = group[j];
                for(k = 1; k < usersInGroup; k++) {
                    unionUsers(first, group[k]);
                }
            }        
        }
    }
    for(i = 1; i <= n; i++) {
        cout << sum[dad[i]] << " ";
    }   
}
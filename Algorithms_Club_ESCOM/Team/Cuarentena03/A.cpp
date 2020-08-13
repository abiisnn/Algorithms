#include<bits/stdc++.h>
using namespace std;
/*rarito el caso 2*/
int main(){
    long long int n, vs, vl, vb;
    cin>>n>>vs>>vb>>vl;
    long long int s, b, l;
    s = vs; b = vb; l = vl;
    vector<int> v(n+2, -1);
    int f = 1; 
    long long int lim = 3*10e9;
    long long int count=0;
    vs=1; vb=1; vl=1;
    int vueltas = 10; 
    while(lim && vueltas){
        vs+=s;
        if(vs>n+1)
            vs-=(n+1);
        if(v[vs]==-1 || v[vs] == 0 || vs==1){
            lim--;
            count++;
            v[vs]=0;
            //cout<<"s "<<vs<<endl;
            
        }else
            break;
        vb+=b;
        if(vb>n+1)
            vb-=(n+1);
        if(v[vb]==-1 || v[vb] == 1 || vb==1){
            lim--;
            count++;
            v[vb]=1;
            //cout<<"b "<<vb<<endl;
            
        }else
            break;
        vl+=l;
        if(vl>n+1)
            vl-=(n+1);
        if(v[vl]==-1 || v[vl] == 2 || vl ==1){
            lim--;
            count++;
            v[vl]=2;
            //cout<<"l "<<vl<<endl;
        }else
            break;
        vueltas--;
    }
    
    if(vueltas == 0 && lim != 0)
        cout<<3000000000<<endl;
    else
        cout<<count+1<<endl;
    return 0;
}
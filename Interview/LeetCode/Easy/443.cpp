#include<bits/stdc++.h>
using namespace std;
int numberDigits(int n) {
    int cont = 0;
    while(n) {
        n /= 10;
        cont++;
    }
    return cont;
}
// current = 1, n = 2
void addNumber(vector<char> &chars, int &current, int n) {
    int nDig = current + numberDigits(n) - 1; // nDig = 1 + 1 -1= 1
    current = nDig + 1; // current = 2
    while(n) {
        int digit = n % 10; // 2
        char digChar = digit + '0'; // 2
        chars[nDig] = digChar; // 
        nDig--;
        n /= 10;   
    }
}
// ["a","2","b","b","c","c","c"]
int compress(vector<char>& chars) {
    int current = 0, cont = 0;
    char last = 34; // last = a, cont = 2
    for(int i = 0; i < chars.size(); i++) {
        if(chars[i] == last) { // a == b NO
             cont++;
        } else {
            if(cont) { // cont = 2
                chars[current] = last; // 
                current++; // current = 1
            }
            if(cont > 1) { // cont = 2
                addNumber(chars, current, cont);
            }
            cont = 1;
        }
        last = chars[i];
    }
    if(cont) { // cont = 2
        chars[current] = last; // 
        current++; // current = 1
    }
    if(cont > 1) { // cont = 2
        addNumber(chars, current, cont);
    }
    return current;
}
int main() {
    int n; cin >> n;
    vector<char> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    } cout << endl;
    cout << "respuesta: " << compress(v) << endl;
    for(int i = 0; i < n; i++) {
        cout << v[i] << " ";
    } cout << endl;
}
#include<bits/stdc++.h>
#define A 1000
#define B 1000
using namespace std;
 
int matrix[A][B];
 
int tamA, tamB;
int total = 0;
int cont = 0;
string a, b;
 
int number(char a) {
    int num = a - 65 ;
    return num;
}
 
int dp(int i, int j) {
    if(i >= tamA)
        return 0;
    if(j >= tamB)
        return 0;
    
    // Yo no he sido visitado
    if(matrix[i][j] == -1) {
        matrix[i][j] = 0;
        if(number(a[i]) == number(b[j])) {
            matrix[i][j]++;
            total++;
            return matrix[i][j] += dp(i+1, j+1);
        }
        else {
            return matrix[i][j] += max(dp(i+1, j+1), max(dp(i+1 , j), dp(i, j+1)));
        }
        
    }
    else {
        return matrix[i][j];
    }
}
void reset(){
    for(int i = 0; i < tamA; i++){
        for(int j = 0; j < tamB; j++){
            matrix[i][j] = -1;
        }
    }
}
int main() {
        cin >> a >> b;
        tamA = a.length(); tamB = b.length();
        reset();
        cout << dp(0, 0) << endl;
}
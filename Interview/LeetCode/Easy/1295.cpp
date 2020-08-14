int numberDigits(int n) {
    int cont = 0; 
    while(n) {
        n /= 10;
        cont++;
    }
    return cont;
}
int findNumbers(vector<int>& nums) {
    int cont = 0;
    for(int i = 0; i < int(nums.size()); i++) {
        if(!(numberDigits(nums[i]) & 1)) {
            cont++;    
        }
    }
    return cont;
}
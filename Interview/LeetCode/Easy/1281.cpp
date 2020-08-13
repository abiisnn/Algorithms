int subtractProductAndSum(int n) {
    long int product = 1;
    long int sum = 0;
    while(n) {
        int dig = n % 10;
            product *= dig;
            sum += dig;
        n /= 10;
    }
    return product - sum;
}
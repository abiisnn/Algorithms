int getLastSix(int num) {
    int i = 0, last = -1;
    while(num) {
        if((num % 10) == 6) {
            last = i;
        }
        num /= 10;
        i++;
    }
    return last;
}
int maximum69Number (int num) {
    int lastSix = getLastSix(num);
    int i = 0, mul = 1, max = 0;
    while(num) {
        int dig = num % 10;
        if(i == lastSix) {
            dig = 9;
        }   
        max += (dig * mul);
        mul *= 10;
        num /= 10;
        i++;
    }
    return max;
}
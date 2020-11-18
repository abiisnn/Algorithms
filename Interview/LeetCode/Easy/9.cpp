int numDig(int x) {
    int size = 0;
    while(x) {
        size++;
        x /= 10;
    }
    return size;
}
/*
    reverse * 10 + dig < INT_MAX
    reverse * 10 < (INT_MAX - dig) 
    reverse  < (INT_MAX - dig) / 10  
*/
int reverseNumber(int x) {
    int reversed = 0;
    while(x) {
        if(reversed > (INT_MAX - (x % 10)) / 10) {
            return 0;
        }
        reversed = (reversed * 10) + (x % 10);
        x/= 10;
    }
    return reversed;
}
bool isPalindrome(int x) {
    if(x < 0) return false;
    int reverse = reverseNumber(x);
    
    bool isPalin = true;
    if(numDig(x) != numDig(reverse)) {
        isPalin = false;
    }
    while(isPalin && x && reverse) {
        if((x % 10) != (reverse % 10)) {
            isPalin = false;
            break;
        }
        x /= 10;
        reverse /= 10;
    }
    return isPalin;
}

/* SECOND SOLUTION */
/*
    reverse * 10 + dig < INT_MAX
    reverse * 10 < (INT_MAX - dig) 
    reverse  < (INT_MAX - dig) / 10  
*/
int reverseNumber(int x) {
    int reversed = 0;
    while(x) {
        if(reversed > (INT_MAX - (x % 10)) / 10) {
            return 0;
        }
        reversed = (reversed * 10) + (x % 10);
        x/= 10;
    }
    return reversed;
}
bool isPalindrome(int x) {
    if(x < 0) return false;
    int reverse = reverseNumber(x);
    return reverse == x;
}
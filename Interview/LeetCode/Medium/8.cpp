/*
    To check that result doesn't overflow: // aux = result
    result = aux * 10 + digit
    result > INT_MAX
    aux * 10 + digit > INT_MAX
    aux > (INT_MAX - digit) / 10  then: OVERFLOW
    this just works if AUX is possitive.
*/

int convert(string &num, bool isNegative) {
    if(num.size() == 0) return 0;
    
    int result = 0;
    for(int i = 0; i < num.size(); i++) {
        int digit = num[i] - '0';
        if (result > ((INT_MAX - digit) / 10) && !isNegative) return INT_MAX;
        if (result > ((INT_MAX - digit) / 10) && isNegative) return INT_MIN;
        result = (result * 10) + digit;
    }
    if(isNegative) result *= -1;
    return result;
}
bool isDigit(char digit){
    return (digit >= '0' && digit <= '9');
}
int myAtoi(string str) {
    int index = 0, i = 0;
    while(i < str.size() && str[i] == ' ') index++,i++;
    
    if(index == str.size()) return 0;
    bool isNegative = false;
    if(str[index] == '-') isNegative = true;
    if(str[index] == '+' or str[index] == '-' ) index++;
    
    string num = "";
    i = index;
    while(i < str.size() && isDigit(str[i])) {
        num += str[i];
        i++;
    }
    return convert(num, isNegative);
}
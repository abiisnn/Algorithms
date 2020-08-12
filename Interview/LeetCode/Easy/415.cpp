 /*
    Can I show leanding zeros?
    Can I have negative numbers?
    Are of the same length?
    
    Important things:
    -> Convert char to int: char - '0'
    -> Convert int to char: int(char)
    
    Cases:
    -> SZnum1 == SZnum2:
        12 + 12 = 24
    -> SZnum1 != SZnum2
        123 
         12 
        135
    -> Possibles sums:
        9 + 9 = 18
*/
/*  Example
    12223
      955
    13178
*/
string addStrings(string num1, string num2) {
    // Fill with zeros the greater string
    string zeros(max(num1.size(), num2.size())-min(num1.size(), num2.size()), '0');
    if(num2.size() > num1.size()) {
        num1 = zeros + num1;
    } else {
        num2 = zeros + num2;
    }
    string ans = "";
    int carry = 0;
    for(int i = int(num2.size()) - 1; i >= 0; i--) {
        int a = num1[i] - '0', b = num2[i] - '0';
        int c = a + b + carry;
        carry = 0;
        if(c > 9) {
            carry = 1; 
            c = c % 10;
        }
        ans = char(c + '0') + ans;
    }
    if(carry) ans = char(carry + '0') + ans;
    return ans;
}
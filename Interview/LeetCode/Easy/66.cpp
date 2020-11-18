vector<int> plusOne(vector<int>& digits) {
    int carry = 1;
    vector<int> result(digits.size(), 0);
    for(int i = digits.size() - 1; i >= 0; i--) {
        result[i] = digits[i] + carry;
        carry = 0;
        if(result[i] >= 10) {
            result[i] = 0;
            carry = 1;
        }
    }
    if(carry) {
        result.push_back(0);
        for(int i = result.size() - 1; i >= 1; i--) {
            result[i] = result[i - 1];
        }
        result[0] = 1;
    }
    return result;
}
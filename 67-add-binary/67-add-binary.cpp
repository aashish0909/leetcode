class Solution {
public:
    string addBinary(string a, string b) {
        string s = "";
        int i = a.size() - 1, j = b.size() - 1;
        int carry = 0;
        
        while(i >= 0 || j >= 0 || carry) {
            carry += (i >= 0 ? a[i--] - '0' : 0);
            carry += (j >= 0 ? b[j--] - '0' : 0);
            
            s = char(carry % 2 + '0') + s;
            carry /= 2;
        }
        
        return s;
    }
};
class Solution {
public:
    int myAtoi(string s) {
        int ans = 0;
        bool neg = false;
        
        int i = 0;
        while(s[i] == ' ') ++i;
        if(s[i] == '+' || s[i] == '-') {
            if(s[i] == '-') neg = true;
            i++;
        }
        
        for(; i < s.size(); i++) {
            int digit = s[i] - '0';
            if(digit < 0 || digit > 9) break;
            
            if((INT_MAX / 10 < ans) || (INT_MAX / 10 == ans && INT_MAX % 10 < digit)) {
                if(neg) return INT_MIN;
                else return INT_MAX;
            }
            
            ans = ans * 10 + digit;
        }
        
        return ans * (neg ? -1 : 1);
    }
};
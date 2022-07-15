class Solution {
public:
    bool isPalindrome(string st) {
        string s = "";
        for(auto c : st) {
            if(isalnum(c)) {
                if(isalpha(c))
                    s += tolower(c);
                else s += c;
            }
        }
        for(int i = 0; 2 * i < s.size(); i++) {
            if(s[i] != s[s.size() - i - 1])
                return false;
        }
        
        return true;
    }
};
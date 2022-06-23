class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.length() - 1, j = t.length() - 1;

        while(true) {
            int count = 0;
            while(i >= 0 && (count > 0 || s[i] == '#')) {
                count += (s[i] == '#' ? 1 : -1);
                i--;
            }
            count = 0;
            while(j >= 0 && (count > 0 || t[j] == '#')) {
                count += (t[j] == '#' ? 1 : -1);
                j--;
            }
            
            if(i >= 0 && j >= 0 && s[i] == t[j]) i--, j--;
            else break;
        }
        
        return (i < 0 && j < 0);
    }
};
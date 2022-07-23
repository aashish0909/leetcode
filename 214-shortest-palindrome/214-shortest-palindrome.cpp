class Solution {
public:
    string shortestPalindrome(string s) {
        if(s.length() <= 1) return s;
        
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        string concat = s + "$" + revStr;
        vector<int> lps(concat.size());
        int i = 1, len = 0;
        while(i < concat.size()) {
            if(concat[i] == concat[len])
                lps[i++] = ++len;
            else if(len > 0)
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
        
        int toAdd = s.size() - lps.back();
        string res = "";
        for(int i = s.size() - 1; i >= s.size() - toAdd; i--)
            res += s[i];
        res += s;
        return res;
    }
};
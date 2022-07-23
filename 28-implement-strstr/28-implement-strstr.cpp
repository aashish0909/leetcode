class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if(needle.size() == 0) return 0;
        
        int n = haystack.size();
        int m = needle.size();
        vector<int> lps(m);
        
        compute(needle, lps);
        
        int i = 0, j = 0;
        while(n - i >= m - j) {
            if(haystack[i] == needle[j])
                ++i, ++j;
            
            if(j == m)
                return (i - j);
            if(i < n && haystack[i] != needle[j]) {
                if(j != 0)
                    j = lps[j - 1];
                else i++;
            }
        }
        
        return -1;
    }
    
    void compute(string needle, vector<int>& lps) {
        int len = 0;
        int i = 1;
        lps[0] = 0;
        while(i < needle.size()) {
            if(needle[i] == needle[len])
                lps[i++] = ++len;
            else if(len > 0)\
                len = lps[len - 1];
            else
                lps[i++] = 0;
        }
    }
};
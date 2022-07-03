class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);
        for(auto i : s) freq[i]++;
        int odd = 0;
        for(auto i : freq) odd += i & 1;
        
        return s.length() - odd + (odd > 0);
    }
};
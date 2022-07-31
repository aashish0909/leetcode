class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        unordered_set<string> words;
        for(auto i : wordDict)
            words.insert(i);
        
        return helper(s, 0, words, dp);
    }
    
    bool helper(string s, int i, unordered_set<string>& words, vector<int>& dp) {
        if(i == s.size())
            return true;
        
        if(dp[i] != -1)
            return dp[i];
        
        string str = "";
        for(int j = i; j < s.size(); j++) {
            str += s[j];
            if(words.count(str))
                if(helper(s, j + 1, words, dp))
                    return dp[i] = true;
        }
        return dp[i] = false;
    }
};
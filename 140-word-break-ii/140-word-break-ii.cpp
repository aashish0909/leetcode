class Solution {
public:
    vector<string> ans;
    void calc(string s, int i, unordered_set<string>& words, string curr) {        
        if(i == s.size()) {
            curr.pop_back();
            ans.push_back(curr);
            return;
        }
        string str = "";
        for(int idx = i; idx < s.length(); idx++) {
            str += s[idx];
            if(words.count(str)) {
                calc(s, idx + 1, words, curr + str + " ");
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words;
        for(auto i : wordDict)
            words.insert(i);
        string curr = "";
        calc(s, 0, words, curr);
        return ans;
    }
};
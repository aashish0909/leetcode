class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> a(26), b(26);
        
        for(auto i : ransomNote) a[i - 'a']++;
        for(auto i : magazine) b[i - 'a']++;
        
        for(int i = 0; i < 26; i++)
            if(a[i] > b[i]) return false;
        
        return true;
    }
};
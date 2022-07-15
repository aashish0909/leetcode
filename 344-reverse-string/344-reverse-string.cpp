class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0; 2 * i < s.size(); i++) {
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};
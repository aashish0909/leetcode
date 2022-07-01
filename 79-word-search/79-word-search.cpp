class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (found(board, word, i, j, 0)) return true;
            }
        }

        return false;
    }

    bool found(vector<vector<char>>& board, string word, int i, int j, int k) {
        if (k == word.length()) return true;
        if (i < 0 || j < 0 || i == board.size() || j == board[i].size()) 
            return false;
        
        if(board[i][j] != word[k]) return false;

        board[i][j] = '0';

        bool ans = found(board, word, i + 1, j, k + 1)
                   || found(board, word, i, j + 1, k + 1)
                   || found(board, word, i - 1, j, k + 1)
                   || found(board, word, i, j - 1, k + 1);

        board[i][j] = word[k];

        return ans;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9], cols[9], box[9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j];
                int boxno = (i / 3) * 3 + (j / 3);
                if (rows[i].count(num) || cols[j].count(num) ||
                    box[boxno].count(num))
                    return false;
                    rows[i].insert(num);
                    cols[j].insert(num);
                    box[boxno].insert(num);

            }
        }
            return true;
        }
    };
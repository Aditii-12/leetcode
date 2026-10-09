class Solution {
public:
    int minInsertions(string s) {
        int ins = 0;
        int lc = 0;
        int len=s.size();
        int ind= 0;
        while (ind<len) {
            char c = s[ind];
            if (c == '(') {
                lc++;
                ind++;
            } else {
                if (lc > 0) {
                    lc--;
                } else {
                    ins++;
                }
                if (ind < len - 1 && s[ind + 1] == ')') {
                    ind+= 2;
                } else {
                    ins++;
                    ind++;
                }
            }
        }
        ins+=lc* 2;
        return ins;
    }
};
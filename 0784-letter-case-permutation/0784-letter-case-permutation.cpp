class Solution {
public:
    vector<string> ans;
    void func(int idx, string curr, string &s) {
        if (idx==s.size()) {
            ans.push_back(curr);
            return;
        }
        if (isdigit(s[idx])) {
            func(idx+1,curr+s[idx],s);
        }
        else {
            func(idx+1,curr+(char)tolower(s[idx]),s);
            func(idx+1,curr+(char)toupper(s[idx]),s);
        }
    }

    vector<string> letterCasePermutation(string s) {
        func(0,"",s);
        return ans;
    }
};
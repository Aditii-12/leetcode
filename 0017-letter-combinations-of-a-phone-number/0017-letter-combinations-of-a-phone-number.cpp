class Solution {
public:
    vector<string>ans;
    string st="";
    vector<string>mp={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void func(int idx,string digits){
        if(idx==digits.size()){
            ans.push_back(st);
            return;
        }
        for(auto it:mp[digits[idx]-'0']){
            st.push_back(it);
            func(idx+1,digits);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        func(0,digits);
        return ans;
    }
};
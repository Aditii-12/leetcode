class Solution {
public:
    vector<string>ans;
    vector<string>mp={ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    void func(int idx,string &curr,string digits){
        if(curr.size()==digits.size()){
            ans.push_back(curr);
            return;
        }
        string let=mp[digits[idx]-'0'];
        for(char ch:let){
            curr+=ch;
            func(idx+1,curr,digits);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        string curr="";
        func(0,curr,digits);
        return ans;
        
    }
};
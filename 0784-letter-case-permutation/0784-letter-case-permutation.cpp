class Solution {
public:
    vector<string>ans;
    void func(int idx,string& curr,string& s){
        if(curr.size()==s.size()){
            ans.push_back(curr);
            return;
        }
        if(isdigit(s[idx])){
            curr+=s[idx];
            func(idx+1,curr,s);
            curr.pop_back();
        }
        else{
            curr+=(tolower(s[idx]));
            func(idx+1,curr,s);
            curr.pop_back();
            curr+=(toupper(s[idx]));
            func(idx+1,curr,s);
            curr.pop_back();
        }
    }
    vector<string> letterCasePermutation(string s) {
        string curr="";
        func(0,curr,s);
        return ans;
    }
};
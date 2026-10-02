class Solution {
public:
vector<string>res;
    void solve(int n,string ans,int o,int c){
        if(ans.length()==2*n){
                res.push_back(ans);
            return;}
        if(o<n){
        ans.push_back('(');
        solve(n,ans,o+1,c);
        ans.pop_back();}
    if(c<o){
        ans.push_back(')');
        solve(n,ans,o,c+1);
        ans.pop_back();
    }
    }
    vector<string> generateParenthesis(int n) {
        string ans="";
        int o=0,c=0;
        solve(n,ans,o,c);
        return res;
    }
};
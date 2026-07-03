class Solution {
public:
    vector<string>ans;

    void dfs(int last,string s,int n){
        if(s.length()==n) {
            ans.push_back(s);
            return;
        }
        if(last==0){
            dfs(1,s+'1',n);
        }
        else{
            dfs(0,s+'0',n);
            dfs(1,s+'1',n);
        }

    }
    vector<string> validStrings(int n) {
        dfs(0,"0",n);
        dfs(1,"1",n);
        return ans;
    }
};
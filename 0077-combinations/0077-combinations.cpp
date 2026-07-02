class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,vector<int>&p,int k){
        if(path.size()==k) {
            ans.push_back(path);
            return;}
        int n=p.size();
        for(int i=idx;i<n;i++){
            path.push_back(p[i]);
            func(i+1,p,k);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int>p(n);
        for(int i=1;i<=n;i++){
            p[i-1]=i;
        }
        func(0,p,k);
        return ans;
    }
};
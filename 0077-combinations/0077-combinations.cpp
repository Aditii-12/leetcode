class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,int k,int n){
        if(path.size()==k) {
            ans.push_back(path);
            return;}
        for(int i=idx;i<=n;i++){
            path.push_back(i);
            func(i+1,k,n);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        func(1,k,n);
        return ans;
    }
};
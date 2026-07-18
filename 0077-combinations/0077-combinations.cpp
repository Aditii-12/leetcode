class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,int k,int n){
        if(path.size()==k) {
            ans.push_back(path);
            return;}
        if(idx>n) return;
        path.push_back(idx);
        func(idx+1,k,n);
        path.pop_back();
        func(idx+1,k,n);
    }
    vector<vector<int>> combine(int n, int k) {
        func(1,k,n);
        return ans;
    }
};
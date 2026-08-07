class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,int k,int n){
        if(path.size()==k && n==0) {
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<=9;i++){
            path.push_back(i);
            func(i+1,k,n-i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        func(1,k,n);
        return ans;
    }
};
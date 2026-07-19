class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int i,int k,int n){
        if(n==0 && path.size()==k) {
            ans.push_back(path);
            return;
        }
        for(int j=i;j<=9;j++){
            path.push_back(j);
            func(j+1,k,n-j);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        func(1,k,n);
        return ans;
    }
};
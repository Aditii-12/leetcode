class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    int sz;
    void func(int idx,int tar){
        if(path.size()==sz && tar==0){
            ans.push_back(path);
            return;
        }
        if(path.size()==sz || tar<=0) return;
        for(int i=idx;i<=9;i++){
            if(i>tar) break;
            path.push_back(i);
            func(i+1,tar-i);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        sz=k;
        func(1,n);
        return ans;
    }
};
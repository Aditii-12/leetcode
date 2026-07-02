class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,int tar,vector<int> cand){
        if(tar==0){
            ans.push_back(path);
            return;
        }
        if(tar<0) return;
        int n=cand.size();
        for(int i=idx;i<n;i++){
            if(i>idx && cand[i]==cand[i-1]) continue;
            if(cand[i]>tar) break;
            path.push_back(cand[i]);
            func(i+1,tar-cand[i],cand);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int tar) {
        sort(cand.begin(),cand.end());
        func(0,tar,cand);
        return ans;
    }
};
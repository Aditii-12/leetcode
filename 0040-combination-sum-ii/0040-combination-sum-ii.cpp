class Solution {
public:
    vector<vector<int>>ans;
    vector<int>path;
    void func(int idx,vector<int>& cand,int tar){
        if(tar==0){
            ans.push_back(path);
            return;
        }
        for(int i=idx;i<cand.size();i++){
            if(i>idx && cand[i]==cand[i-1]) continue;
            if(cand[i]>tar) break;
            path.push_back(cand[i]);
            func(i+1,cand,tar-cand[i]);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int tar) {
        sort(cand.begin(),cand.end());
        func(0,cand,tar);
        return ans;
    }
};
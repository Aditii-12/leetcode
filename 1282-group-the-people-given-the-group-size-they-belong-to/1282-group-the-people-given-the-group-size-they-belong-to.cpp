class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupsz) {
        int n=groupsz.size();
        unordered_map<int,vector<int>>mpp;
        for(int i=0;i<n;i++){
            mpp[groupsz[i]].push_back(i);
        }
        vector<vector<int>>ans;
        for(auto &[sz,ind]:mpp){
            vector<int>curr;
            for(int p:ind){
                curr.push_back(p);
                if(curr.size()==sz) {
                    ans.push_back(curr);
                    curr.clear();
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mpp;
        int cnt=0;
        for(auto it:nums){
            mpp[it]++;
            cnt=max(cnt,mpp[it]);
        }
        vector<vector<int>>v(cnt);
        for(auto it:mpp){
            int num=it.first;
            int freq=it.second;
            for(int i=0;i<freq;i++){
                v[i].push_back(num);
            }
        }
        return v;
    }
};
class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums) mpp[it]++;
        int ans=-1;
        unordered_map<int,int>sec;
        for(auto it:mpp){
            sec[it.second]++;
        }
        for(auto it:nums){
            if(sec[mpp[it]]==1) return it;
        }
        return -1;

    }
};
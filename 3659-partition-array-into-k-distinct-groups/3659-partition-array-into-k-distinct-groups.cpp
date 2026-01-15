class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0) return 0;
        unordered_map<int,int>freq;
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        int size=n/k;
        for(auto it:freq){
            if(it.second>size) return 0;
        }
        return 1;
    }
};
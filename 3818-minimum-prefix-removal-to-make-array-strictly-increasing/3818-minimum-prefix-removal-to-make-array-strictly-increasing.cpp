class Solution {
public:
    bool check(vector<int>& nums, int i){
        for(int j=i+1;j<nums.size()-1;j++){
            if(nums[j]>=nums[j+1]) return 0; //not strictly increasing
        }
        return 1;
    }
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        if(check(nums,-1)) return 0;
        for(int i=0;i<n-1;i++){
            if(check(nums,i)) return i+1;
        }
        return n;
    }
};
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int prev=0,inc=1;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                inc++;
            }
            else {prev=inc;
            inc=1;} 
            if(inc>=2*k ||min(inc,prev)>=k){
                return true;
            }

        }
        return false;
    }
};
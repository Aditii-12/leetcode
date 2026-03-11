class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0;
        int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target) return mid;
            if(nums[mid]>=nums[lo]){ //means left half is sorted
                if(nums[lo]<=target && nums[mid]>=target){ //means ussi me lie krta h
                    hi=mid;
                }
                else lo=mid+1;
            }
            else if(nums[mid]<=nums[hi]){ //right half is sorted
                if(nums[mid]<=target && nums[hi]>=target){
                    lo=mid;
                }
                else hi=mid-1;
            }
        }
        return -1;

    }
};
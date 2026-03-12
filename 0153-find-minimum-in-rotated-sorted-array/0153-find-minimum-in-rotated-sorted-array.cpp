class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];

        int lo=0;
        int hi=n-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1; //agr nums[mid]>nums[hi] to min lies in right part
            else hi=mid;
        }
        return nums[lo]; //end me loop tb khtm hoga
        //jb lo==hi vhi minimum element hoga
    }
};
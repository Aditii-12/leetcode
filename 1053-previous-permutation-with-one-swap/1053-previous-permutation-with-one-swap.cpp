class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& nums) {
        int n=nums.size();
        int i=n-1;
        while(i>0 && nums[i-1]<=nums[i]) i--;
        if(i==0) return nums;
        i--;
        int j=i+1;
        int temp=-1;
        int bst=-1;
        while(j<n){
            if(nums[j]<nums[i]){
                if(nums[j]>temp){
                    temp=nums[j];
                    bst=j;
                }
            }
            j++;
        }
        swap(nums[i],nums[bst]);
        return nums;

    }
};
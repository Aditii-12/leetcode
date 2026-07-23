class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> arr(nums.size());
        int p=0,n=1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                arr[p]=nums[i];
                p=p+2;
            }
            else{
                arr[n]=nums[i];
                n=n+2;
            }
        }
        return arr;
    }
};
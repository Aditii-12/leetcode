class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int l=0; //pointer for maintaing 0
        int h=n-1; //pointer for maintaining 2
        int i=0; //moving pointer
        while(i<=h){
            if(nums[i]==0) {
                swap(nums[i],nums[l]);
                l++;
                i++;
            }
            else if(nums[i]==2){
                swap(nums[i],nums[h]);
                h--;
            }
            else i++;
        }
    }
};
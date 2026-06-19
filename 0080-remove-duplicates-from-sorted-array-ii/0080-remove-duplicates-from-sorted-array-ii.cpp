class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int slow=2;
        for(int f=2;f<n;f++){
            if(nums[f]!=nums[slow-2]){
                nums[slow]=nums[f];
                slow++;
            }
        }
        return slow;
    }
};
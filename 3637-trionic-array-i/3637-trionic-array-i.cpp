class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n=nums.size();
        if (n<4) return 0;

        int st=0;  //starting state
        for (int i=0;i<n-1;i++) {
            if (st==0) {
                if(nums[i]<nums[i+1]){
                    //increasing as it should be
                }else if(i>0&&nums[i]>nums[i+1]) {
                    st=1; //reached peak ab decrease hona chahiye
                }else {
                    return 0;
                }
            }else if(st==1) {
                if (nums[i]>nums[i+1]) {
                    //decreasing as it should be
                }else if(nums[i]<nums[i+1]) {
                    st=2;//Reached valley ab firse increase hoga
                }else {
                    return 0;
                }
            }else if(st==2) {
                if (nums[i]<nums[i+1]) {
                    //increasing again
                }else{
                    return 0;
                }
            }
        }
        return st==2;
    }
};
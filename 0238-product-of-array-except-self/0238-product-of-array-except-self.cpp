class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long overall_1=1;
        bool flag=0;
        int nozero=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0){
                flag=true;
                nozero++;
            }else{
                overall_1*=nums[i];
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nozero>1){
                nums[i]=0;
            }else if(nozero==1){
                nums[i]=nums[i]==0 ?overall_1:0;
            }else{
                nums[i]=overall_1/nums[i];
            }
        }
        return nums;
    }
};
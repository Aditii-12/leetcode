class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int cnt1=0;
            for(int num:nums){
                if((num&(1<<i))) cnt1++;
            }
            ans+=(cnt1)*(n-cnt1);
        }
        return ans;
    }
};
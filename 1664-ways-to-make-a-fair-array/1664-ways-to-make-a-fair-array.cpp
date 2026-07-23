class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return 1;
        int ev=0;
        int odd=0;
        int lefte=0, lefto=0;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(i%2==0) ev+=nums[i];
            else odd+=nums[i];
        }
        for(int i=0;i<n;i++){
            if(i%2==0) ev-=nums[i];
            else odd-=nums[i];
            if(lefte+odd==ev+lefto){
                cnt++;
            }
            if(i%2==0) lefte+=nums[i];
            else lefto+=nums[i];
        }
        return cnt;
    }
};
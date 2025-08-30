class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        int cnt1=0; //cnt of odd numbers
        int l=0,r=0;
        int ans=0;
        int cnte=0; //cnt of continous even number in start to add in cnt
        while(r<n){
            if(nums[r]%2==1) cnt1++;
            while(l<r&&(cnt1>k||nums[l]%2==0)){
                if(nums[l]%2==0) cnte++;
                else cnte=0;
                if(nums[l]%2==1) cnt1--;
                l++;
            }
            if(cnt1==k){
                ans+=cnte+1;
            }
            r++;
        }
        return ans;

    }
};
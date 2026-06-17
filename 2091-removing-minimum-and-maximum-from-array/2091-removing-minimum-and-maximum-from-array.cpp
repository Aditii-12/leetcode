class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int l1=-1;
        int l2=-1;
        int r1=-1;
        int r2=-1;
        int maxi=*max_element(nums.begin(),nums.end());
        int mini=*min_element(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==maxi) {
                if(l1==-1) l1=i;
                r1=n-i-1;
            }
            if(nums[i]==mini){
                if(l2==-1) l2=i;
                r2=n-i-1;
            }
        }
        int ans=INT_MAX;
        ans=min(max(l1,l2)+1, max(r1,r2)+1);
        ans=min(ans,(l1+1)+r2+1);
        ans=min(ans,(l2+1)+r1+1);
        return ans;
    }
};
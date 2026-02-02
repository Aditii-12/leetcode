class Solution {
public:
//nums[l...r] in this all is <=nums[r];
//cost to convert all to nums[r] is nums[r]*windowsize-(total sum)
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long sum=0;
        int l=0,r=0;
        int ans=0;
        while(r<n){
            sum+=nums[r];
            //if cost exceeds k. shrink window
            while((long long)nums[r]*(r-l+1)-sum>k){
                sum-=nums[l];
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
        

    }
};
class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int ans=0;
        for (int i=0;i<n;i++) {
            int pos=upper_bound(nums.begin(),nums.end(),nums[i])-nums.begin();
            //this will give first ppsition where it is strcitly greater than our number
            if (n-pos>=k)
                ans++;
        }
        return ans;
    }
};

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        multiset<int> st;
        int l=0,r=0;
        int ans=0;
        while(r<n)
        {
            st.insert(nums[r]);
            while(*st.rbegin()-*st.begin()>limit)
            //maxi-min
            {
                st.erase(st.find(nums[l]));
                l++;
            }
            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};
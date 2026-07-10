class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n=nums.size();
        stack<int>st;
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top()>nums[i] && st.size()-1+n-i>=k){
                st.pop();
            }
            st.push(nums[i]);
        }
        while(st.size()>k) st.pop();
        vector<int>ans(st.size());
        for(int i=k-1;i>=0;i--){
            ans[i]=st.top();
            st.pop();
        }
        return ans;
    }
};
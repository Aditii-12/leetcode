class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1); // Result array initialized with -1
        stack<int> st; // Stack to track next greater elements

        // Traverse twice to simulate circular behavior
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums[i % n]) {
                st.pop();
            }
            if (i < n) { // Fill answers only in the first pass
                ans[i] = st.empty() ? -1 : st.top();
            }
            st.push(nums[i % n]); // Push current element (circular index)
        }
        
        return ans;
    }
};

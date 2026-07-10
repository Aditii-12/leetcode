class Solution {
public:
//monotonic decreasing stack
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans(nums1.size(),-1);
        unordered_map<int,int>nge;
        stack<int>st;
        for(int i=nums2.size()-1;i>=0;i--){
            while(!st.empty() && st.top()<=nums2[i]){
                st.pop();
            }
            nge[nums2[i]]=(st.empty())?-1:st.top();
            st.push(nums2[i]);
        }
        for(int i=0;i<nums1.size();i++){
            ans[i]=nge[nums1[i]];
        }
        return ans;
    }
};
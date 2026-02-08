class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        int n=nums.size();
        stack<long long>st;
        for(int i=0;i<n;i++){
            long long num=nums[i];
            while(!st.empty() && st.top()==num){
                num+=st.top();
                st.pop();
            }
            st.push(num);
        }
        vector<long long>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
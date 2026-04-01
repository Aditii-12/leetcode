class Solution {
public:
//next greater element kitne elements bd ayega
//monotonic decreasing stack
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        stack<int>st;
        vector<int>ans(n,0);
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && temp[st.top()]<=temp[i]){
                st.pop();
            }
            //ab jo top pr bcha h voi next greater temp h to bs distance lelnge
            if(!st.empty())
                ans[i]=st.top()-i;
            st.push(i);
        }
        return ans;
    
    }
};
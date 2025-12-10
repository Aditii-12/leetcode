class Solution {
public:
    int clumsy(int n) {
        stack<int>st;
        int op=0;
        st.push(n);
        int curr=n-1;
        while(curr>0){
            if(op==0){
                int top=st.top();
                st.pop();
                st.push(top*curr);
            }
            else if(op==1){
                int top=st.top();
                st.pop();
                st.push(top/curr);
            }
            else if(op==2){
                st.push(curr);
            }
            else st.push(-1*curr);
            op=(op+1)%4;
            curr--;
        }
        int ans=0;
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        return ans;
    }
};
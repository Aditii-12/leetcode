class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        string ans="";
        for(auto it:s){
            if(it!='*') st.push(it);
            else{
                st.pop();
            }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
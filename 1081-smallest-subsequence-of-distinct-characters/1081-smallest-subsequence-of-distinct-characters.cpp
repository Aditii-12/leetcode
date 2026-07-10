class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.size();
        vector<int>last(26);
        vector<bool>vis(26,0);
        for(int i=0;i<n;i++){
            last[s[i]-'a']=i;
        }
        stack<char>st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(vis[ch-'a']) continue;
            while(!st.empty() && st.top()>s[i] && last[st.top()-'a']>i){
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(ch);
            vis[ch-'a']=1;
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;

        for(char c:num){
            while(!st.empty() && st.top()>c && k>0){
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0){ //agr already increasing order me hi h to k bch jayega
            //to end se htadenge
            st.pop();
            k--;
        }
        string res="";
        while(!st.empty()){
            res+=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        //aage ke zeros htayenge
        int i=0;
        while(i<res.size() && res[i]=='0') i++;
        res=res.substr(i);
        return res=="" ? "0" : res;
    }
};
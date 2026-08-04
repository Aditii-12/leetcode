class Solution {
public:
    string decodeString(string s) {
        stack<string> ch;
        stack<int> num;
        int n=0;
        string ans;
        for(auto it:s){
            if(isdigit(it)){
                n=n*10 + it-'0';
            }
            else if(it=='['){
                
                ch.push(ans);
                num.push(n);
                ans="";
                n=0;
            }
            else if(it==']'){
                string temp=ans;
                int i=num.top();
                num.pop();
                ans=ch.top();
                ch.pop();
                while(i--){
                    ans+=temp;
                }
            }
            else {
                ans+=it;
            }
        }
        return ans;
        }
    
};
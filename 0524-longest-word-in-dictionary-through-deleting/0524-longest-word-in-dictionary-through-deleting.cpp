class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        string ans="";
        for(string p:dictionary){
            int l=0; //on string s
            int r=0; //on string p
            while(l<s.length() && r<p.length()){
                if(s[l]==p[r]){
                    l++;
                    r++;
                }
                else l++;
                if(r==p.length()){
                    if(p.length()>ans.length()) ans=p;
                    else if(p.length()==ans.length()) ans=min(p,ans);
                }
            }
        }
        return ans;
    }
};
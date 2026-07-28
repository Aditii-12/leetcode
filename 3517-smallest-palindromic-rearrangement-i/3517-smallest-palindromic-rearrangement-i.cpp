class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.length();
        vector<int>freq(26,0);
        string ans="";
        for(auto it:s) freq[it-'a']++;
        char ch;
        for(int i=0;i<26;i++){
            if(freq[i]%2==0){
                ans.append(freq[i]/2,i+'a');
            }
            else{
                ch=i+'a';
                ans.append(freq[i]/2,i+'a');
            }
        }
        if(n%2==1){
            string p=ans;
            ans+=ch;
            reverse(p.begin(),p.end());
            ans+=p;
        }
        else{
            string p=ans;
            reverse(p.begin(),p.end());
            ans+=p;
        }
        return ans;
        
    }
};
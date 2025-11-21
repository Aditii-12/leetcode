class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_set<char>l;
        for(char c:s){
            l.insert(c);
        }
        int ans=0;
        for(char le:l){
            int i=-1;
            int j=0;
            for(int k=0;k<s.size();k++){
                if(s[k]==le){
                    if(i==-1) i=k; //first occurence
                    j=k;
                }
            }
            unordered_set<char>bt; //uske bich me kitcne char h
            //first and last apperance ke bich me
            for(int k=i+1;k<j;k++){
                bt.insert(s[k]); //so we will count only unique characters in between
            }
            ans+=bt.size();
        }
        return ans;
        
    }
};
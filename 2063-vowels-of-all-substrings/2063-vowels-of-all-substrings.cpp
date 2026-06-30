class Solution {
public:
    bool isvow(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    long long countVowels(string word) {
        long long ans=0;
        int n=word.length();
        for(int i=0;i<n;i++){
            char ch=word[i];
            if(isvow(ch)){
                ans+=1LL*(i+1)*(n-i);
            }
        }
        return ans;
    }
};
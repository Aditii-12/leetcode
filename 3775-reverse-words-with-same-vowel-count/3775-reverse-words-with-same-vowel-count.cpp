class Solution {
public:
    bool isvow(char ch){
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        ss >> word;
        string ans=word;
        int cnt=0;
        for(char ch:word){
            if(isvow(ch)) cnt++;
        }
        while(ss>>word){
            ans+=" ";
            int temp=0;
            for(char ch:word){
                if(isvow(ch)) temp++;
            }
            if(temp==cnt) reverse(word.begin(),word.end());
            ans+=word;
        }
        return ans;

    }
};
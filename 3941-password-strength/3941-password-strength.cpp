class Solution {
public:
    bool sm(char c){
        return c<='z'&&c>='a';
    }
    bool b(char c){
        return c<='Z'&&c>='A';
    }
    bool n(char c){
        return c<='9'&&c>='0';
    }
    bool sp(char c){
        return c=='!'||c=='@'||c=='#'||c=='$';
    }
    int passwordStrength(string s) {
        int ans=0;
        unordered_set<char>st(s.begin(),s.end());
        for(auto c:st){
            if(sm(c)) ans++;
            else if(b(c)) ans+=2;
            else if(n(c)) ans+=3;
            else if(sp(c)) ans+=5;
        }
        return ans;
    }
};
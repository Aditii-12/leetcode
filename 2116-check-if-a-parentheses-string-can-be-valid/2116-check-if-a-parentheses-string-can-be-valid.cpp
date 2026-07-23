class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n=s.length();
        if(n%2!=0) return 0;
        int op=0;
        int fr=0;
        for(int i=0;i<n;i++){
            if(locked[i]=='0') fr++;
            else if(s[i]=='(') op++;
            else{
                if(op>0) op--;
                else if(fr>0) fr--;
                else return 0;
            }
        }
        int cl=0;
        fr=0;
        for(int i=n-1;i>=0;i--){
            if(locked[i]=='0') fr++;
            else if(s[i]==')') cl++;
            else{
                if(cl>0) cl--;
                else if(fr>0) fr--;
                else return 0;
            }
        }
        return 1;
    }
};
class Solution {
public:
    string convert(string s, int numr) {
        int n=s.length();
        if(numr==1||numr>=n) return s;
        vector<string>v(numr);
        int row=0;
        bool f=1; //if 1 the going down if 0 coming up
        for(char ch:s){
            v[row]+=ch;
            if(row==0) f=1;
            else if(row==numr-1) f=0;
            if(f==1) row++;
            if(f==0) row--;
        }
        string ans="";
        for(auto it:v) ans+=it;
        return ans;
    }
};
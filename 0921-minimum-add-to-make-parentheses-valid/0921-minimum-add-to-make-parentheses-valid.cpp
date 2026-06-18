class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int o=0;
        int c=0;
        for(auto it:s){
            if(it=='(') o++;
            else {
                if(o>0) o--;
                else c++;
            }
        }
        return o+c;
    }
};
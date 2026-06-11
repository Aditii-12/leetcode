class Solution {
public:
    int minFlips(string s) {
        int cnt0=0,cnt1=0;
        for(char c:s){
            if(c=='0') cnt0++;
            else cnt1++;
        }
        if(!cnt1 || !cnt0) return 0; //if there are only one or zeros then return 0
        return min(cnt0,cnt1-(s.front()&s.back()&1)-1); 
    }
};
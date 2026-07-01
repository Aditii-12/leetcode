class Solution {
public:
    int magicalString(int n) {
        if(n<=3) return 1;
        string s="122";
        int head=2;
        char num='1';
        int ones=1;
        while(s.size()<n){
            int cnt=s[head]-'0';
            for(int i=0;i<cnt;i++){
                s+=num;
                if(num=='1'&& s.size()<=n){
                    ones++;
                }
            }
            if(num=='1') num='2';
            else num='1';
            head++;
        }
        return ones;
    }
};
class Solution {
public:
using ll=long long;
    long long sumAndMultiply(int n) {
        ll x=0;
        ll s=0;
        string st=to_string(n);
        for(char c:st){
            if(c!='0'){
                x=x*10+c-'0';
                s+=c-'0';
            }
        }
        return x*s;
    }
};
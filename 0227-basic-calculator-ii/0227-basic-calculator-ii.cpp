#define ll long long
class Solution {
public:
    int calculate(string s) {
        int n=s.length();
        ll ans=0;
        ll last=0;
        ll num=0;
        char op='+'; //pehla op + manlete h
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(isdigit(ch)){
                num=num*10+(ch-'0');
            }
            if((!isdigit(ch) && ch!=' ' )|| i==n-1){
                //mtlb ya to jb operator ho ya last char pr ho tb evaluate krenge
                //ch is operator currently encountering
                //op is last encountered operator
                if(op=='+'){ //to previous wale operator ko evaluate krenge
                    ans+=last;
                    last=num;
                }
                else if(op=='-'){
                    ans+=last;
                    last=-num;
                }
                else if(op=='*'){
                    last=last*num;
                }
                else if(op=='/'){
                    last/=num;
                }
                op=ch;
                num=0;
            }
        }
        ans+=last;
        return ans;


    }
};
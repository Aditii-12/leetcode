#define ll long long
class Solution {
public:
    long long minimumCost(string s, string t, int flipc, int swapc, int crossc) {
        if(s==t) return 0;
        int n=s.length();
        ll a=0; //number of pairs where s[i] is 1 and t[i] is 0
        ll b=0; //number of pairs where t[i] is 1 and s[i] is 1
        for(int i=0;i<n;i++){
            if(s[i]=='1' && t[i]=='0') a++;
            else if(t[i]=='1' && s[i]=='0') b++;
        }
        ll k=a+b;
        //if we flip everything
        ll co=k*flipc;
        ll pairs=min(a,b);
        ll cost1=1LL*swapc*pairs;
        a-=pairs;
        b-=pairs;
        k-=2*pairs;
        ll cost2=cost1+1LL*flipc*k;

        ll c3=cost1+(k/2)*1LL*(crossc+swapc)+(k%2) *flipc;
        return min(co,min(cost2,c3));

    }
};
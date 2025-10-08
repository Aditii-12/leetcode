class Solution {
using ll=long long;
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        int n=spells.size();
        int n2=potions.size();
        sort(potions.begin(),potions.end());
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ll temp=spells[i];
            ll l=0;
            ll h=n2-1;
            int res=-1;
            while(l<=h){
                int m=l+(h-l)/2;
                if(potions[m]*temp>=success){
                    res=m;
                    h=m-1;
                }
                else l=m+1;
            }
            if(res==-1) ans[i]=0;
            else ans[i]=n2-res;
        }
        return ans;

    }
};
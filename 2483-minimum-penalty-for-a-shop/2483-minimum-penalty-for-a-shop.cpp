class Solution {
public:
    int bestClosingTime(string cust) {
        int n=cust.size();
        int tot=0;
        for(auto it:cust){
            if(it=='Y') tot++;
        }
        int ans=tot;
        int idx=0;
        int penalty=0;
        for(int i=0;i<n;i++){
            if(ans>penalty+tot){
                ans=penalty+tot;
                idx=i;
            }
            if(cust[i]=='N') penalty++;
            else tot--;
        }
        if(ans>penalty){
            idx=n;
        }
        return idx;
    }
};
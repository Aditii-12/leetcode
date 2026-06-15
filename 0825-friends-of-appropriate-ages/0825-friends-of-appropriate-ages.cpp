class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        sort(ages.begin(),ages.end());
        int n=ages.size();
        int ans=0;
        int l=0;
        int r=0;
        for(int i=0;i<n;i++){
            while(l<n && ages[l]<=0.5*ages[i]+7) l++;
            while(r+1<n && ages[r+1]<=ages[i]) r++;
            if(r>=l) ans+=(r-l);
        }
        return ans;
    }
};
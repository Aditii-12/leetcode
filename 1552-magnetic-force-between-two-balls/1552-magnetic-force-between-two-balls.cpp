class Solution {
public:
    bool func(int mid,vector<int>& pos,int m){
        int pre=pos[0];
        int cnt=1;
        for(int i=1;i<pos.size();i++){
            int curr=pos[i];
            if(curr-pre>=mid){
                cnt++;
                pre=curr;
            }
            if(cnt==m) break;
        }
        return cnt==m;
    }
    int maxDistance(vector<int>& pos, int m) {
        int n=pos.size();
        sort(pos.begin(),pos.end());
        int l=1;
        int r=pos[n-1]-pos[0];
        int ans=l;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(func(mid,pos,m)){
                ans=mid;
                l=mid+1;
            }
            else r=mid-1;
        }
        return ans;
    }
};
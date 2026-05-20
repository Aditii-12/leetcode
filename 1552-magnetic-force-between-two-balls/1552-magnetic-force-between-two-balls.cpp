class Solution {
public:
    bool func(int mid,vector<int>&pos,int m){
        int pre=pos[0]; //pehla ball rkhenge
        int cnt=1; //we need to check ki sare balls place kiye ya ni 
        for(int i=1;i<pos.size();i++){
            int curr=pos[i];
            if(curr-pre>=mid) 
            {cnt++;
            pre=pos[i];
            }
            if(cnt==m) break;
        }
        return cnt==m;
    }
    int maxDistance(vector<int>& position, int m) {
        int n=position.size();
        sort(position.begin(),position.end());
        int l=1;
        int r=position[n-1]-position[0];
        int ans=l;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(func(mid,position,m)) {
                ans=mid;
                l=mid+1; //ab or bda dhudenge
            }
            else r=mid-1;
        }
        return ans;
    }
};
class Solution {
public:
    bool func(int mid,vector<int>& bd,int m,int k){
        int bou=0;
        int temp=0;
        for(int i=0;i<bd.size();i++){
            if(bd[i]<=mid){
                temp++;
                if(temp==k) {
                    bou++;
                    temp=0;
                }
            }
            else{
                temp=0;
            }
            if(temp==k) bou++;
        }
        return bou>=m;
    }
    int minDays(vector<int>& bd, int m, int k) {
        if((long long)m*k>bd.size()) return -1;
        int l=1;
        int h=*max_element(bd.begin(),bd.end());
        int ans=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(mid,bd,m,k)){
                ans=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};
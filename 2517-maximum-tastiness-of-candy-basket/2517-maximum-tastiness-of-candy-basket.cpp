class Solution {
public:
    bool func(int mid,vector<int>& price,int k){
        int cnt=1;
        int prev=price[0];
        for(int i=1;i<price.size();i++){
            if(price[i]-prev>=mid){
                cnt++;
                prev=price[i];
            }        
        }
        return cnt>=k;
    }
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(),price.end());
        int l=0;
        int ans=0;
        int r=price[price.size()-1]- price[0];
        while(l<=r){
            int mid=l+(r-l)/2;
            if(func(mid,price,k)){
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};
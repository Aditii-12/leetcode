class Solution {
public:
    bool func(int mid,vector<int>&w,int days){
        int d=0;
        int sum=0;
        for(int i=0;i<w.size();i++){
            sum+=w[i];
            if(sum>mid){
                d++;
                sum=w[i];
            }
        }
        if(sum>0) d++;
        return d<=days;
    }
    int shipWithinDays(vector<int>& w, int days) {
        int l=*max_element(w.begin(),w.end());
        int h=accumulate(w.begin(),w.end(),0);
        int ans=0;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(m,w,days)){
                ans=m;
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool func(vector<int>& wts,int days,int mid){
        int n=wts.size();
        int temp=0;
        int t=0;
        for(int i=0;i<n;i++){
            t+=wts[i];
            if(t>mid){
                temp++;
                t=wts[i];
            }
            else if(t==mid){
                temp++;
                t=0;
            }
        }
        if(t>0) temp++;
        return temp<=days;

    }
    int shipWithinDays(vector<int>& wts, int days) {
        int n=wts.size();
        int lo=*max_element(wts.begin(),wts.end());
        int hi=accumulate(wts.begin(),wts.end(),0);
        int ans;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(func(wts,days,mid)){
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans;
    }
};
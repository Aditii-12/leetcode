class Solution {
public:
    int func(vector<int>&wt ,int mid){
        int days=0;
        int sum=0;
        for(int i=0;i<wt.size();i++){
            sum+=wt[i];
            if(sum>mid){
                days++;
                sum=wt[i];
            }
            else if(sum==mid){
                days++;
                sum=0;
            }
        }
        if(sum>0) days++;
        return days;
    }
    int shipWithinDays(vector<int>& wt, int days) {
        int n=wt.size();
        int ans=-1;
        int low=*max_element(wt.begin(),wt.end());
        int high=accumulate(wt.begin(),wt.end(),0LL);
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(wt,mid)>days){
                low=mid+1;
                //weight bdhana pdega jo that kam din lge
            }
            else{
                ans=mid;
                high=mid-1;
                //weight kam krne ka try krenge
            }
        }
        return ans;
        
    }
};
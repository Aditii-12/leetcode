class Solution {
public:
    bool func(vector<int>&bloom,int m,int k,int mid){
        int n=bloom.size();
        int bou=0;
        int flo=0; 
        for(int i=0;i<n;i++){
            if(bloom[i]<=mid){
                flo++;
                if(flo==k) {
                    bou++;
                    flo=0;
                }
            }
            else{
                flo=0; //reset
                //as they need to be adjacent
            }
        }
        if(bou>=m) return 1;
        return 0;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        if((long long)m*k> bloom.size()) return -1;
        int n=bloom.size();
        int l=1;
        int ans=-1;
        int h=*max_element(bloom.begin(),bloom.end());
        while(l<=h){
            int mid=l+(h-l)/2;
            if(func(bloom,m,k,mid)){
                ans=mid;
                h=mid-1; //chota ans dhudne ka try krenge
            }
            else{
                l=mid+1;
            }
        }
        return ans;

    }
};
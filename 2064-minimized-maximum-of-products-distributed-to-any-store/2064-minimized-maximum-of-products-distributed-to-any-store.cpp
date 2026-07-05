class Solution {
public:
    bool func(int mid,vector<int>& quantities,int n){
        if(mid==0) return 0;
        int temp=0;
        for(int i=0;i<quantities.size();i++){
            if(quantities[i]%mid==0){
                temp+=quantities[i]/mid;
            }
            else temp+=quantities[i]/mid+1;
        }
        return temp<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=*max_element(quantities.begin(),quantities.end());
        int ans=-1;
        while(l<=h){
            int m=l+(h-l)/2;
            if(func(m,quantities,n)){ 
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
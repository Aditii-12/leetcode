class Solution {
public:
    bool func(int mid,vector<int>& quantities,int n){
        // int j=0;
        // int rem=quantities[j];
        // //max we can give to a store is mid
        // for(int i=0;i<n;i++){
        //     if(rem<=mid){
        //         j++;
        //         if(j==quantities.size()) return 1; 
        //         //end me aagye and sare baat diya 
        //         else{
        //             rem=quantities[j]; //set to next product
        //         }
        //     }
        //     else{
        //         rem-=mid;
        //     }
        // }
        // return 0;

        //SECOND APPROACH IS(OTIMIZED ONE)
        //IS THAT FOR A MAX QUANITY WHICH IS PASSED IN A FUCNTION
        //WE CALCULATE NUMBER OF STORES WE NEED
        //IF THAT<=N RETURN 1;
        //ELSE RETURN 0
        if(mid==0) return 0;
        int temp=0;
        for(int i=0;i<quantities.size();i++){
            temp+=ceil((double)quantities[i]/mid);
        }
        return temp<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int l=1;
        int h=*max_element(quantities.begin(),quantities.end());
        //max is jb highest quantity wala item pura ek hi store ko dediya
        int ans=-1;
        while(l<=h){
            
            int m=l+(h-l)/2;
            if(func(m,quantities,n)){ //agr baat skte h to then we search for a smaller
            //answer
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
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int cnt=count(nums.begin(),nums.end(),1);
        //we need window of cnt length to have max one. bs baki ones ko swap krdenge
        if(cnt<=1) return 0; //koi swap ni krenge
        vector<int>arr(2*n);
        for(int i=0;i<2*n;i++){
            arr[i]=nums[i%n];
        }
        //first window 
        int one=0;
        for(int i=0;i<cnt;i++){
            if(arr[i]==1) one++;
        }
        int maxi=one;
        int l=0;
        int r=cnt;
        while(r<2*n){
            one+=arr[r];
            one-=arr[l];
            l++;
            maxi=max(maxi,one);
            r++;
        }
        return cnt-maxi; 
    }
};
class Solution {
public:
//DIFFERENCE ARAAY WITH BINARY SEARCH
    int n;
    int m;
    bool func(vector<int>& nums, vector<vector<int>>& queries,int k){
        vector<int>diff(n+1,0);
        for(int i=0;i<=k;i++){ //use queries 0..k
            int l=queries[i][0];
            int r=queries[i][1];
            int sub=queries[i][2];

            diff[l]-=sub;
            diff[r+1]+=sub;
        }
        // nums[0]+=diff[0]; 
        //CANNOT MODIFY NUM 
        int curr=0;
        for(int i=0;i<n;i++){
            curr+=diff[i];
            if(nums[i]+curr>0) return 0;
        }
        return 1;
    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        n=nums.size();
        m=queries.size();
        int zeros = count(nums.begin(),nums.end(),0);
        if(zeros==n) return 0;
        int lo=0;
        int hi=m-1;
        int ans=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(func(nums,queries,mid)==1) {
                ans=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        return ans==-1?-1:ans+1;
        //THIS WILL GIVE TLE SP BETTER USE BS
        // for(int i=0;i<m;i++){
        //     if(func(nums,queries,i)==1) //pehle ke i queries check krke dekhlenge
        //         return i+1;//1 based 
        // }
        // return -1;
    }
};
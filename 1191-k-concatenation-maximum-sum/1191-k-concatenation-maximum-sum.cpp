class Solution {
public:
const int MOD=1e9+7;
    long long kadane(vector<int>& nums){
        long long sum=0;
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
            ans=max(ans,sum);
            if(sum<0) sum=0;
        }
        return ans;
    }
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long total=accumulate(arr.begin(),arr.end(),0LL);
        if(k==1) return kadane(arr);

        vector<int>temp=arr;
        temp.insert(temp.end(),arr.begin(),arr.end()); //this creates temp=arr+arr

        long long b=kadane(temp);
        if(total<=0){
            return b%MOD;
        }
        else{
            return (b+total*(k-2) )%MOD;
        }
        return 0;

    }
};
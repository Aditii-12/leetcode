class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        const int MOD=1e9+7;
        int sum=0;
        int n=arr.size();
        int ans=0;
        int even=0; //cnt of even sums abi tk
        int odd=0; //cnt of odd sums abi tk
        even+=1; //empty array sum=even
        for(int i=0;i<n;i++){
            sum+=arr[i];
            if(sum%2==0){
                ans=(ans+odd)%MOD;
                even++;
            }
            else{
                ans=(ans+even)%MOD;
                odd++;
            }
        }
        return ans%MOD;
    }
};
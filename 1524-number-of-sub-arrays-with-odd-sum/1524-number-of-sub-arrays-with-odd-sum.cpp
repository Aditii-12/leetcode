class Solution {
public:
    const int MOD=1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int odd=0;
        int even=1;
        int sum=0;
        int ans=0;
        for(auto it:arr){
            sum+=it;
            if(sum%2==0){
                ans+=odd;
                even++;
            }
            else {
                ans+=even;
                odd++;
            }
            ans%=MOD;
        }
        return ans;
    }
};
class Solution {
public:
//xor(l...r) == prexor[r] xor prexor[l-1]
//prexor[i]= prefix xor
//i tk ke sare xor
//xor(l...r) is 0 only when prexor[l-1]==prexor[r]

//second thing we also need to find balance between odd and even
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        int odd=0;
        int even=0;
        map<pair<int,int>,int>mpp;
        int xorr=0;
        int ans=0;
        mpp[{0,0}]=-1;
        for(int i=0;i<n;i++){
            xorr^=nums[i];
            if(nums[i]%2==0) even++;
            else odd++;
            int diff=even-odd;
            pair<int,int>key={xorr,diff};
            if(mpp.count(key)){ //same key already exist
                ans=max(ans,i-mpp[key]); //i-mp[key] is length of subraay
            }
            else mpp[key]=i; //this is the first index jaha ye milra h
        }
        return ans;
    }
};
class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n=nums.size();
        vector<bool>f(n,0);
        f[n-1]=1; //last element alswways strcitly increqsing
        //basically f will store kaha se array strcitly increasing h

        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]&&f[i+1])
                f[i]=1;
            else
                f[i]=0;
        }
        for(int i=-1;i<n-1;i++){
            if(f[i+1])
                return i+1;
        }

        return n;
    }
};

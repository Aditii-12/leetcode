class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>fir;
        fir[0]=-1;
        int cnt=0;
        int ans=0;
        int i=0;
        for(auto it:nums){
            if(it==1)cnt++;
            else cnt--;
            if(fir.find(cnt)!=fir.end()){
                ans=max(ans,i-fir[cnt]);
            }
            else fir[cnt]=i;
            i++;
        }
        return ans;
    }
};
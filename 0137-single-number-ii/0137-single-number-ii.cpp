class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int i=0;i<32;i++){
            int cnt=0;
            for(int num:nums){
                if(1&(num>>i)) cnt++;
            }
            if(cnt%3==1) res|=(1<<i);
        }
        return res;
    }
};
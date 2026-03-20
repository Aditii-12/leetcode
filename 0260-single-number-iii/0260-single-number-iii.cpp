class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int c=0;
        for(auto num:nums){
            c^=num;
        }
        int diff = c & (-(long long)c);
        int a=0; //group1
        int b=0; //group2
        for(auto it:nums){
            if((it&diff)==0) a^=it;
            else b^=it;
        }
        return {a,b};

    }
};
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        set<int>s;
        for(auto x:nums) s.insert(x);
        while(s.count(original)!=0){
            s.insert(original);
            original*=2;
        }
    return original;
    }
};
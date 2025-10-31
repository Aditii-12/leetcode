class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int>st;
        vector<int>v;
        for(int x:nums){
            if(st.count(x)) 
                v.push_back(x);
            else
                st.insert(x);
        }
        return v;
    }
};

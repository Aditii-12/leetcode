class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int m=nums.size();
        string res="";
        for(int i=0;i<m;i++){
            if(nums[i][i]=='0'){
                res+='1';
            }
            else res+='0';
        }
        return res;
    }
};
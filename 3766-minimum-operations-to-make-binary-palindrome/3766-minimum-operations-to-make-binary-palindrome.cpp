class Solution {
public:
    bool isp(int x){
        if(x==0) return 1;
        string s;
        while(x){
            if(x&1) s+=('1');
            else s+=('0');
            x>>=1;
        }
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    vector<int> minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>p;
        for(int i=0;i<=5000;i++){
            if(isp(i)) p.push_back(i);
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            int b=INT_MAX;
            for(auto it:p){
                b=min(b,abs(it-nums[i]));
            }
            ans.push_back(b);
        }
        return ans;
    }
};
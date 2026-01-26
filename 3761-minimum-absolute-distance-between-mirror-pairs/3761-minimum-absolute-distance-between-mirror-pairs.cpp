class Solution {
public:
    int reverse(int x){
        int res=0;
        while(x){
            res=res*10+x%10;
            x/=10;
        }
        return res;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>last; 
        //in this hm reverse krke store krate jayenge with distance
        //and aagr aage hme same number mila to disance calulcate krlenge
        last[reverse(nums[0])]=0;

        int res=INT_MAX;
        for(int i=1;i<n;i++){
            if(last.count(nums[i])){
                res=min(res,i-last[nums[i]]);
            }
            //update last seeen
            last[reverse(nums[i])]=i;
        }
        if(res==INT_MAX) return -1;
        return res;
    }
};
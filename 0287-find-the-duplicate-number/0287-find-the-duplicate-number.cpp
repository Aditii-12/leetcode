class Solution {
public:
//l =1 h=n 
//iske bich hi hoga vo integer now we will calculate mid
//fir dekhenge mid se chote kitne number h arrays h
//if that count>mid  to uske left me hi lie kregea
// 1 3 4 2 2 
//l=1 h=4 if mid=2 count<=2 is 3 so duplicate lies in [1,2]
    int findDuplicate(vector<int>& nums) {
        int lo=1;
        int hi=nums.size()-1;
        while(lo<hi){
            int mid=lo+(hi-lo)/2;
            int cnt=0;
            for(auto it:nums){
                if(it<=mid) cnt++;
            }
            if(cnt>mid) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};
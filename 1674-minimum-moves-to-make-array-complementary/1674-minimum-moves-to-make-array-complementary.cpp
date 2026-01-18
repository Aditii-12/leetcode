class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        //in this vector index represent sum
        //0th index= means our target sum is 0
        //1th index means target sum is 1
        //kyuki sum can be in range of 2 to limit*2
        //jb dono number 1 ho to 2 and dono number limit ho to 2*limit
        for(int i=0;i<n/2;i++){ //in this we process pairs 
            int a=nums[i];
            int b=nums[n-i-1];
            int sum=a+b;
            // NOW we have a and b so we see by making only 1 change what sum can be get
            //so we can get sum in range [low,high]
            //in this we have to make only chnge
            //except if sum=target sum so we need 0 changes
            //and outside this range we need 2 changes
            int low=1+min(a,b);
            int high=limit+max(a,b);

            diff[2]+=2; //we assume every sum needs 2 operations for this pair
            //sum starts with 2 so diff[2]++;
            diff[low]--; //low se high tk sirf 1 operation chahiye so we subtract diff[low]-- 
            //so low se high tk 2 operation se 1 minus krdiya to 1 operation
            diff[sum]--; //kyuki sum pr to 0 operations chhaiye so -1
            //but uske aage se to 1 lgega so plus one on sum+1
            diff[sum+1]++;
            diff[high+1]++; //high ke bd ke range ke sums me is pair ke liye 2 hi lgenge so add fot that
        }


        //now out diff array contain ki ek sum pr total kitne chnages lgenge 
        //for that we have to take prefix sum
        int ans=INT_MAX;
        int curr=0;
        for(int s=2;s<=2*limit;s++){ //ye hmare sum ki range h 
            curr+=diff[s];
            ans=min(ans,curr); //we need minimum operations
        }
        return ans;
    }
};
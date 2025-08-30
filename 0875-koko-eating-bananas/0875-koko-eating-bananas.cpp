class Solution {
public:
    long long func(vector<int>& piles, int speed) {
        long long hours = 0;
        for (int i = 0; i < piles.size(); i++) {
            hours += (piles[i] + speed - 1) / speed; // ceil division
        }
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(piles,mid)>h) {
                low=mid+1; //speed to bdhana pdega
            }
            else{
                ans=mid;
                high=mid-1;
            }
        }
        return ans;
    }
};
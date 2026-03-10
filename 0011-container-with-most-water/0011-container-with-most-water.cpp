class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int l=0;
        int r=n-1;
        int ans=INT_MIN;
        while(l<r){
            ans=max(ans,min(heights[l],heights[r])*(r-l));
            if(heights[l]<heights[r]) l++;
            else r--; //kyuki ans is dependent on choti height 
            //to choti height rkhke fayda ni h so pointer move krdenge
        }
        return ans;
    }
};
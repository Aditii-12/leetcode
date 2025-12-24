class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int sum=0;
        for(int i=0;i<apple.size();i++){
            sum+=apple[i];
        }
        int ans=0;
        for(int i=0;i<capacity.size();i++){
            sum-=capacity[i];
            ans++;
            if(sum<=0) break;
        }
        return ans;
    }
};
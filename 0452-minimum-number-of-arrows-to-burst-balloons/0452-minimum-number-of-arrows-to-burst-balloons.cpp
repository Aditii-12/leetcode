class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int ans=1; //ek arrow to marenge hi
        int target=points[0][1];
        //basically dekhenge ki next point target se pehle khtm hora h kya
        //to vo jo arrow chlri h usme hi hojayega
        for(int i=1;i<n;i++){
            if(points[i][0]<=target){
                target=min(target,points[i][1]);
            }
            else{
                ans++;
                target=points[i][1];
            }
        }
        return ans;

    }
};
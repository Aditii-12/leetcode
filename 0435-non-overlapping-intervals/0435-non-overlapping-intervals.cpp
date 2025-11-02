class Solution {
public:
//IF WE SORT BY STARTING TIME
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        int cnt=0;
        int i=0;
        int j=1;
        while(j<n){
            vector<int> curr_int=intervals[i];
            vector<int> next_int=intervals[j];
            int cs=curr_int[0]; //current start
            int ce=curr_int[1]; //current end
            int ns=next_int[0]; //next start
            int ne=next_int[1]; //next end
            if(ce<=ns){ //no overlapping
                i=j;
                j++;
            }
            else if(ce<=ne){ //overlapping
            //deleting j wala interval kyuki uska end time bht h
                j++;
                cnt++;
            }
            else if(ne<ce){ //deleting i wala interval kuyuki uska end time bht h
                i=j;
                j++;
                cnt++;
            }
        }
        return cnt;
        
    }
};
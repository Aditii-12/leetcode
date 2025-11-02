class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        vector<vector<int>> ans;
        sort(people.begin(),people.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]>b[0];
        });
        //sorting with descending order
        //and if equal to k in ascending order
        //7,0 7,1 6,1 5,0
        //now place at index given in kth position
        // place 7 at 0th index ans-- 7,0
        //then another 7 at 1st index --7,0 7,1
        //then 6 aya uska k=1 to 1st index pr place krenge and shift krdenge to right
        //7,0 6,1 7,1
        //order will be preserved
        for(auto it:people){
            ans.insert(ans.begin()+it[1],it);
            //index,value to be inserted
        }
        return ans;

    }
};
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        for(int i=0;i<n;i++){
            pq.push({matrix[0][i],0,i});
        }
        k--;
        while(k--){
            auto curr=pq.top();
            pq.pop();
            int r=curr[1];
            int c=curr[2];
            if(r+1<n){
                pq.push({matrix[r+1][c],r+1,c});
            }
        }
        return pq.top()[0];
    }
};
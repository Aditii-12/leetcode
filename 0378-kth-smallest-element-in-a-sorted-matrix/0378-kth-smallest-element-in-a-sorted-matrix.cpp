class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<vector<int>,vector<vector<int>>,greater<>>pq;
        int n=matrix[0].size();
        for(int i=0;i<min(n,k);i++){
            pq.push({matrix[i][0],i,0});
        }
        k--;
        while(k-- && !pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int i=curr[1];
            int j=curr[2];
            if(j+1<n){
                pq.push({matrix[i][j+1],i,j+1});
            }
        }
        return pq.top()[0];
    }
};
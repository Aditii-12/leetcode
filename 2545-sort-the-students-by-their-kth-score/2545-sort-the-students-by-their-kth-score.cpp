class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n=score.size();
        int m=score[0].size();
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++){
            pq.push({score[i][k],i});
        }
        vector<vector<int>>res;
        while(!pq.empty()){
            int r=pq.top().second;
            pq.pop();
            res.push_back(score[r]);
        }
        return res;
    }
};
class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq;
        for(auto it:piles) pq.push(it);
        while(k--){
            int x=pq.top();
            pq.pop();
            x-=x/2;
            pq.push(x);
        }
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};
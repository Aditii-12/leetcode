class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n=costs.size();
        int i=0;
        int j=n-1;
        priority_queue<int,vector<int>,greater<int>>p; //min heap
        priority_queue<int,vector<int>,greater<int>>q;
        long long ans=0;
        while(k--){
            while(p.size()<candidates && i<=j) {
                p.push(costs[i]);
                i++;
            }
            while(q.size()<candidates && i<=j){
                q.push(costs[j]);
                j--;
            }
            int t1=p.empty()?INT_MAX:p.top();
            int t2=q.empty()?INT_MAX:q.top(); //kyuki ho skta h ek heap khali hojaye 
            //but dusra rhega to empty wala case we will check
            //jese 4 h total costs but candidares is 3
            //to p me 3 q me 1 kyuki common ni
            // or fir q wala hi choose hogya to q empty hojayega
            if(t1<=t2){
                ans+=t1;
                p.pop();
            }
            else{
                ans+=t2;
                q.pop();
            }
        }
        return ans;
    }
};
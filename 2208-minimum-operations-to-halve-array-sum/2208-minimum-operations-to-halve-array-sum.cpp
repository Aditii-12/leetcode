class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double>pq;
        double sum=0;
        for(auto it:nums){
            pq.push(it);
            sum+=it;
        }
        double temp=sum;
        int k=0;
        while(1){
            if(sum/2>=temp) return k;
            double t=pq.top();
            pq.pop();
            t/=2;
            temp-=t;
            pq.push(t);
            k++;
        }
        return k;
    }
};
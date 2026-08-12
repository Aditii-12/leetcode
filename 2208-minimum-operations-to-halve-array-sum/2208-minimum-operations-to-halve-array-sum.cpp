class Solution {
public:
    int halveArray(vector<int>& nums) {
        int n=nums.size();
        priority_queue<double>pq;
        double sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            pq.push(nums[i]);
        }
        double temp=sum;
        int k=0;
        while(true){
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
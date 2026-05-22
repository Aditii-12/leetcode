class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        priority_queue<pair<int,char>>pq; //simple max heap
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans;
        while(!pq.empty()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            ans.append(freq,ch);

        }
        return ans;
    }
};
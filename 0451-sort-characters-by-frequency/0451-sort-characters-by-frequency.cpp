class Solution {
public:
    string frequencySort(string s) {
        priority_queue<pair<int,char>>pq;
        unordered_map<char,int>mpp;
        for(auto it:s){
            mpp[it]++;
        }
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        while(!pq.empty()){
            ans.append(pq.top().first,pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
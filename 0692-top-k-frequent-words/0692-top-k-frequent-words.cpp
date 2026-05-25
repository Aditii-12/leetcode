class cmp{
    public:
    bool operator()(pair<int,string>a,pair<int,string>b){
        if(a.first==b.first) return a.second>b.second;
        return a.first<b.first;
    }
};
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string>ans;
        unordered_map<string,int>mpp;
        for(int i=0;i<words.size();i++){
            mpp[words[i]]++;
        }
        priority_queue<pair<int,string>,vector<pair<int,string>>,cmp>pq;
        for(auto &it:mpp){
            pq.push({it.second,it.first});
        }
        while(k-- && !pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
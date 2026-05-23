class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>mpp;
        for(auto it:s) mpp[it]++;
        priority_queue<pair<int,char>>pq;
        for(auto it:mpp){
            pq.push({it.second,it.first});
        }
        string ans="";
        pair<int,char> prev={0,'#'};
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int freq=it.first;
            char ch=it.second;
            ans+=ch;
            freq--;
            if(prev.first>0) pq.push(prev);
            prev={freq,ch};
        }
        if(ans.size()!=s.size()) return "";
        return ans;
    }
};
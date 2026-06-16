class Solution {
public:
    string repeatLimitedString(string s, int lim) {
        vector<int>freq(26,0);
        string ans="";
        for(auto it:s){
            freq[it-'a']++;
        }
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<26;i++){
            if(freq[i]!=0) pq.push({i,freq[i]});
        }
        while(!pq.empty()){
            auto [ch,f]=pq.top();
            pq.pop();
            int t=min(f,lim);
            ans.append(t,ch+'a');
            f-=t;
            if(f==0) continue;
            if(pq.empty()) break;
            auto[c2,f2]=pq.top();
            pq.pop();
            ans+=(c2+'a');
            f2--;
            if(f2>0) pq.push({c2,f2});
            pq.push({ch,f});
        }
        return ans;

    }
};
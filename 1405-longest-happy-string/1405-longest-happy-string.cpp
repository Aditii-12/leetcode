class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>>pq;
        if(a>0) pq.push({a,'a'});
        if(b>0) pq.push({b,'b'});
        if(c>0) pq.push({c,'c'});
        string ans="";
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            auto freq=it.first;
            auto ch=it.second;
            if(ans.size()>=2 && ans.back()==ch && ans[ans.size()-2]==ch){
                if(pq.empty()) break;
                auto itt=pq.top();
                pq.pop();
                auto freq2=itt.first;
                auto ch2=itt.second;
                ans+=ch2;
                freq2--;
                if(freq2>0) pq.push({freq2,ch2});
                pq.push({freq,ch});
            }
            else{
                ans+=ch;
                freq--;
                if(freq>0) pq.push({freq,ch});
            }
        }
        return ans;
    }
};
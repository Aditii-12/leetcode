class Solution {
public:
    string predictPartyVictory(string senate) {
        int n=senate.size();
        queue<int>r;
        queue<int>s;
        for(int i=0;i<senate.size();i++){
            if(senate[i]=='R') r.push(i);
            else s.push(i);
        }
        while(!r.empty() && !s.empty()){
            int p=r.front();
            int q=s.front();
            r.pop();
            s.pop();
            if(p<q){
                r.push(p+n);
            }
            else{
                s.push(q+n);
            }
        }
        if(r.empty()) return "Dire";
        else return "Radiant";
    }
};
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string>dead(deadends.begin(),deadends.end());
        if(dead.count("0000")) return -1;
        queue<string>q;
        q.push("0000");
        unordered_set<string>vis;
        vis.insert("0000");
        int steps=0;
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                string curr=q.front();
                q.pop();
                if(curr==target) return steps;
                for(int i=0;i<4;i++){
                    string up=curr;
                    string down=curr;
                    up[i]=(curr[i]=='9')?'0':curr[i]+1;
                    down[i]=(curr[i]=='0')?'9':curr[i]-1;
                    if(!dead.count(up) && !vis.count(up)) {
                        q.push(up);
                        vis.insert(up);
                    }
                    if(!dead.count(down) && !vis.count(down)) {
                        q.push(down);
                        vis.insert(down);
                    }
                }
            }
            steps++;
        }
        return -1;

    }
};
class Solution {
public:
    int minMutation(string startgene, string endgene, vector<string>& bank) {
        unordered_set<string>st(bank.begin(),bank.end());
        if(!st.count(endgene)) return -1;
        queue<string>q;
        q.push(startgene);
        int steps=0;
        vector<char> g={'A','C','G','T'};
        while(!q.empty()){
            int sz=q.size();
            for(int i=0;i<sz;i++){
            string curr=q.front();
            q.pop();
            if(curr==endgene) return steps;
            for(int i=0;i<=7;i++){
                char old=curr[i];
                for(char ch:g){
                    curr[i]=ch;
                    if(st.count(curr)){
                        q.push(curr);
                        st.erase(curr);
                    }
                }
                curr[i]=old;
            }
        }
        steps++;
        }
        return -1;
      
    }
};
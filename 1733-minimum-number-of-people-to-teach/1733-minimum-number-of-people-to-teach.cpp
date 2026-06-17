class Solution {
public:
    int minimumTeachings(int m, vector<vector<int>>& lang, vector<vector<int>>& fr) {
        int n=lang.size();
        vector<unordered_set<int>>know(n);
        for(int i=0;i<n;i++){
            for(auto it:lang[i]){
                know[i].insert(it);
            }
        }
        unordered_set<int>bp;
        for(auto it:fr){
            int u=it[0]-1;
            int v=it[1]-1;
            bool f=0;
            for(auto it:know[u]){
                if(know[v].count(it)) {
                    f=1;
                    break;
                }
            }
            if(f==0){
                bp.insert(u);
                bp.insert(v);
            }
        }
        int ans=INT_MAX;
        for(int l=1;l<=m;l++){
            int teach=0;
            for(int p:bp){
                if(!know[p].count(l)) teach++;
            }
            ans=min(ans,teach);
        }
        return ans;
    }
};
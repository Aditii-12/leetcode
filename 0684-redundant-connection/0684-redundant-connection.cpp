class Solution {
public:
vector<int>par;
vector<int>rank;
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    void unionn(int x,int y){
        int u=find(x);
        int v=find(y);
        if(u==v) return;
        if(rank[u]<rank[v]){
            par[u]=v;
        }
        else if(rank[v]<rank[u]){
            par[v]=u;
        }
        else{
            par[u]=v;
            rank[v]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=1;i<n+1;i++){
            par[i]=i;
        }
        for(auto e:edges){
            int u=e[0];
            int v=e[1];
            if(find(u)==find(v)) return {e[0],e[1]};
            else{
                unionn(e[0],e[1]);
            }
        }
        return {};

    }
};
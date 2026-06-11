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
    if(rank[u]>rank[v]) par[v]=u;
    else if(rank[v]>rank[u]) par[u]=v;
    else{
        par[u]=v;
        rank[u]++;
    }
}
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        par.resize(n+1);
        rank.resize(n+1,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        for(int d=threshold+1;d<=n;d++){
            for(int j=2*d;j<=n;j+=d){
                unionn(d,j);
            }
        }
        vector<bool>ans;
        for(auto q:queries){
            if(find(q[0])==find(q[1])){
                ans.push_back(1);
            }
            else ans.push_back(0);
        }
        return ans;
    }
};
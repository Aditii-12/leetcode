class Solution {
public:
vector<int>par,rank;
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unionn(int x,int y){
        int u=find(x);
        int v=find(y);
        if(u==v) return;
        if(rank[u]>rank[v])
            par[v]=u;
        else if(rank[u]<rank[v])
            par[u]=v;
        else{
            par[v]=u;
            rank[u]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++)
            par[i]=i;
        vector<vector<int>> edges;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int wt=
                abs(points[i][0]-points[j][0])
                +
                abs(points[i][1]-points[j][1]);
                edges.push_back({
                    wt,i,j
                });
            }
        }
        sort(edges.begin(),edges.end());
        int cost=0;
        for(auto &e:edges){
            int wt=e[0];
            int u=e[1];
            int v=e[2];
            if(find(u)!=find(v)){
                unionn(u,v);
                cost+=wt;
            }
        }
        return cost;
    }
};
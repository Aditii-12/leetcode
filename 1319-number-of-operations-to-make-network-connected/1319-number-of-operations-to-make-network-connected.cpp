class Solution {
public:
vector<int>par;
vector<int>rank;
int find(int x){
    if(par[x]==x) return x;
    return par[x]=find(par[x]);
}
void unionn(int x,int y){
    int x_par=find(x);
    int y_par=find(y);
    if(rank[x_par]>rank[y_par]) par[y_par]=x_par;
    else if(rank[x_par]<rank[y_par]) par[x_par]=y_par;
    else{
        rank[x_par]++;
        par[y_par]=x_par;
    }
}
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m=connections.size();
        if(m<n-1) return -1;
        par.resize(n);
        rank.resize(n,0);
        for(int i=0;i<n;i++){
            par[i]=i;
        }
        int ex=0;
        for(auto it:connections){
            int par1=find(it[0]);
            int par2=find(it[1]);
            if(par1!=par2){
                unionn(it[0],it[1]);
            }
            else{
                ex++;
            }
        }
        int compo=0;
        for(int i=0;i<n;i++){
            if(find(i)==i) compo++;
        }
        if(ex>=compo-1) return compo-1;
        return -1;
    }
};
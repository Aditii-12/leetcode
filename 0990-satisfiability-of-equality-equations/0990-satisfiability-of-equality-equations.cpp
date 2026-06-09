class Solution {
public:
vector<int>parent;
vector<int>rank;
    int find(int x){ 
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int u=find(x);
        int v=find(y);
        if(u==v) return;
        if(rank[u]>rank[v]) parent[u]=v;
        else if(rank[u]<rank[v]) parent[u]=v;
        else {
            rank[u]++;
            parent[u]=v;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26,0);
        rank.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        for(auto it:equations){
            if(it[1]=='=')
                unionn(it[0]-'a',it[3]-'a');
        }
        for(auto it:equations){
            if(it[1]=='!'){
                int x_par=find(it[0]-'a');
                int y_par=find(it[3]-'a');
                if(x_par==y_par) return 0;
            }
        }
        return 1;
        
    }
};
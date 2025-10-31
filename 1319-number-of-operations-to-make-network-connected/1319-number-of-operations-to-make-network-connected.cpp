class Solution {
public:
vector<int>parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        else
            return parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p == y_p) return;
        if(rank[x_p]>rank[y_p]){
            parent[y_p]=x_p;
        }
        else if(rank[x_p]<rank[y_p]){
            parent[x_p]=y_p;
        }
        else {
            parent[x_p]=y_p;
            rank[y_p]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        //we need atleast n-1 edges to connect all
        //connections me edges hi h or
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        rank.resize(n,0);
        int component=n; //no of component
        //hm union lete jayenge and componenet kam krte jayenge
        //end me no of edges required=component-1
        //components ko decrease krte jayenge end me we need 1;
        for(auto it:connections){
            int p_x=find(it[0]);
            int p_y=find(it[1]);
            if(p_x!=p_y) {
                unionn(it[0],it[1]);
                component--;
            }
        }
        return component-1;
        //no of edges required to join all component;
        
    }
};
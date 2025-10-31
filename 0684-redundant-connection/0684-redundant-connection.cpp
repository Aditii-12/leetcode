class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(x==parent[x]) return x;
        else return parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int x_p=find(x);
        int y_p=find(y);
        if(x_p==y_p) return;
        else{
            if(rank[x_p]>rank[y_p]){
                parent[y_p]=x_p;
            }
            else if(rank[x_p] < rank[y_p]){
            parent[x_p] = y_p;
        }
        else {
            parent[x_p] = y_p;
            rank[y_p]++;
        }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //no of edges == no of nodes
        //kyuki bs ek edge extra added h tree h
        //to generally no of nodes=edges-1;
        //but we r given one xtra edge. so no of edges given==no of nodes
        int m=edges.size();
        parent.resize(m+1); //1-indexed
        rank.resize(m+1,0);
        for(int i=1;i<m+1;i++){
            parent[i]=i;
        }
        for(int i=0;i<m;i++){
            int x=edges[i][0];
            int y=edges[i][1];
            int x_p=find(x);
            int y_p=find(y);
            if(x_p==y_p) return{x,y};
            else unionn(x, y);
        }
        return{0,0};
    }
};
class Solution {
public:
vector<int>parent;
vector<int>rank;
    int find(int x){ //for finding the parent of x
        if(parent[x]==x) return x;
        else
            return parent[x]=find(parent[x]);
    }
    void unionn(int x,int y){
        int x_par=find(x);
        int y_par=find(y);
        if(x_par==y_par) return;
        if(rank[x_par]>rank[y_par]) parent[y_par]=x_par;
        else if(rank[x_par]<rank[y_par]) parent[x_par]=y_par;
        else {
            rank[x_par]++;
            parent[y_par]=x_par;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        parent.resize(26,0);
        rank.resize(26,0);
        for(int i=0;i<26;i++) parent[i]=i;
        for(auto it:equations){
            if(it[1]=='=') //mtlb equal h dono
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
class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        unordered_map<int,int>rmin,rmax;
        unordered_map<int,int>cmin,cmax;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            if(!rmin.count(x)){ //x exist hi ni krta to us row ka y min and max hoga
                rmin[x]=y;
                rmax[x]=y;
            }
            else{
                rmin[x]=min(rmin[x],y);
                rmax[x]=max(rmax[x],y);
            }
            if(!cmin.count(y)){
                cmin[y]=x;
                cmax[y]=x;
            }
            else{
                cmin[y]=min(cmin[y],x);
                cmax[y]=max(cmax[y],x);
            }
        }
        int ans=0;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            if(rmin[x]<y && rmax[x]>y && cmin[y]<x && cmax[y]>x) ans++;
        }
        return ans;
    }
};
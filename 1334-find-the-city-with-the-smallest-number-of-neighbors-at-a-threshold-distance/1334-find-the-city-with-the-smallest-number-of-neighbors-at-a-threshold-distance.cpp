class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            dist[i][i]=0;
        }
        for(auto &e:edges) {
            int u=e[0],v=e[1],w=e[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(dist[j][i]==1e9||dist[i][k]==1e9) continue;
                    dist[j][k]=min(dist[j][k],dist[j][i]+dist[k][i]);
                }
            }
        }
        int ans=-1;
        int mini=INT_MAX;
        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                if(dist[i][j]<=dt) cnt++;
            }
            if(cnt<=mini) {ans=i;
            mini=cnt;
            }
        }
        return ans;
    }

};
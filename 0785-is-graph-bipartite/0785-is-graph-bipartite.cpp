class Solution {
public:
    bool isBipartite(vector<vector<int>>& adj) {
        int v=adj.size();
        vector<int>color(v,-1);
        queue<int>q;

        for(int i=0;i<v;i++){
            if(color[i]==-1){
                color[i]=0;
                q.push(i);

                while(!q.empty()){
                    int node= q.front();
                    q.pop();

                    for(int j=0;j<adj[node].size();j++){
                        int nb=adj[node][j];
                        if(color[nb]==-1){
                            q.push(nb);
                            color[nb]= 1-color[node];
                        }
                        
                        else if(color[nb]==color[node]) return false;
                    }
                }

            }
        }
        return true;
    }
};
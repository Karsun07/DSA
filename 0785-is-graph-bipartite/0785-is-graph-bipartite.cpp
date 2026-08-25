class Solution {
public:
    bool bfs(int start,vector<int>&color,vector<vector<int>>&adj){
        
        queue<int>q;
        color[start]=0;
        q.push(start);

        while(!q.empty()){
            int node=q.front();
            q.pop();

            for(int nb:adj[node]){
                
                if(color[nb]==-1){
                    color[nb]=(color[node]+1)%2;
                    q.push(nb);
                }
                else{
                    if(color[node]==color[nb]){
                        return false;
                    }
                }

            }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& adj) {
        int n=adj.size();
        vector<int>color(n,-1);

        queue<int>q;
        for(int i=0;i<n;i++){
            if(color[i]==-1){
                if(!bfs(i,color,adj)) return false;
            }
        }
        return true;
        

       
    }
};
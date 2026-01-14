class Solution {
public:
    int row[4]={-1,1,0,0};
    int col[4]={0,0,-1,1};

    bool valid(int i,int j,int r,int c){
        return i>=0 && j>=0 && i<r && j<c;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0;
        int r=grid.size(),c=grid[0].size();
        queue<pair<int,int>>q;
        int fresh=0;

        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]==2) q.push({i,j});
                else if(grid[i][j]==1) fresh++;
            }
        }

        if(fresh==0) return 0;

        while(!q.empty()){
            int size=q.size();
            bool rot=0;

            while(size--){
                int i= q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int i1=i+row[k];
                    int j1=j+col[k];

                    if(valid(i1,j1,r,c) && grid[i1][j1]==1){
                        rot=1;
                        fresh--;
                        grid[i1][j1]=2;
                        q.push({i1,j1});
                    }
                }
            }
            if(rot) ans++;
        }

        return fresh==0 ? ans : -1;
    }
};

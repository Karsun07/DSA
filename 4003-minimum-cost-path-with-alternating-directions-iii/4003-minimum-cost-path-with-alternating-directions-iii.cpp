class Solution {
public:
    #define ll long long
    long long minCost(int n, int m, vector<vector<int>>& penalty) {

        vector<vector<vector<ll>>> dis(n,vector<vector<ll>> (m,vector<ll> (2,1e18)));

        priority_queue<tuple<ll,int,int,int>,
                        vector<tuple<ll,int,int,int>>,
                        greater<tuple<ll,int,int,int>>> pq;

        dis[0][0][0]=1;
        pq.push({1,0,0,0});

        vector<int> X={1,0,-1,0};
        vector<int> Y={0,1,0,-1};//R D L U

        while(!pq.empty()){
            auto [cst,r,c,par]=pq.top();
            pq.pop();

            if(cst>dis[r][c][par]) continue;

            if(r==n-1 && c==m-1) return cst;

            if(cst+penalty[r][c]<dis[r][c][par^1]){
                dis[r][c][par^1]=cst+penalty[r][c];
                pq.push({cst+penalty[r][c],r,c,par^1});
            }

            for(int dir=0;dir<4;dir++){
                int nr=r+X[dir],nc=c+Y[dir];
                if(nr<0 || nr==n || nc<0 || nc==m) continue;

                int pen=false;

                if(par==0){
                    if(dir==2 || dir==3) pen=true;
                }else{
                    if(dir==0 || dir==1) pen=true;
                }

                ll nextCst=cst+1ll*(nr+1)*(nc+1);
                if(pen){
                    nextCst+=penalty[r][c];
                }

                if(nextCst<dis[nr][nc][par^1]){
                    dis[nr][nc][par^1]=nextCst;
                    pq.push({nextCst,nr,nc,par^1});
                }

            }
        }
        return -1;
    }
};
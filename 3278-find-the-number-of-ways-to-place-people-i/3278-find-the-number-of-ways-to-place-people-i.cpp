class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        for(int i=0;i<n;i++) {
            int x1=points[i][0],y1=points[i][1];
            for(int j=0;j<n;j++) {
                if(i==j)
                    continue;
                int x2=points[j][0],y2=points[j][1];
                bool flag=0;
                if(y1>=y2 && x1<=x2) {
                    for(int k=0;k<n;k++) {
                        if(k==i || k==j)
                            continue;
                        int x3=points[k][0],y3=points[k][1];
                        if(x3>=x1 && x3<=x2 && y3>=y2 && y3<=y1) {
                            flag=1;
                            break;
                        }
                    }
                    if(!flag)
                        ans++;
                }
                
            }
        }
        return ans;
    }
};
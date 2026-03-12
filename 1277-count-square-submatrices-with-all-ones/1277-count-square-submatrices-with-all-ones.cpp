class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size(),c=matrix[0].size();
        int ans=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(matrix[i][j]==0) continue;              
                for(int size=1;size<=min(r-i,c-j);size++){
                    bool yes=1;
                    for(int i2=i;i2<i+size;i2++){
                        for(int j2=j;j2<j+size;j2++){
                            if(matrix[i2][j2]==0){
                                yes=0;
                                break;
                            } 
                        }
                        if(!yes) break;
                    }
                    if(yes) ans++; 
                    else break;
            
                }
            }
        }
        return ans;
    }
};
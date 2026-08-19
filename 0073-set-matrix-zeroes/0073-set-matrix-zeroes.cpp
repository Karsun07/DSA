class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int m=mat.size(),n=mat[0].size();
        vector<int>rowzer(m,0),colzer(n,0);

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    rowzer[i]=1;
                    colzer[j]=1;
                }
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rowzer[i]||colzer[j]){
                    mat[i][j]=0;
                }
            }
        }
     


    }
};

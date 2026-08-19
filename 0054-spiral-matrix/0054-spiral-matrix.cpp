class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();

        int rowi = 0, rowf = m-1;
        int coli = 0, colf = n-1;

        vector<int> ans;

        while(rowi <= rowf && coli <= colf){

            for(int j=coli;j<=colf;j++){
                ans.push_back(matrix[rowi][j]);
            }
            rowi++;


            for(int i=rowi;i<=rowf;i++){
                ans.push_back(matrix[i][colf]);
            }
            colf--;


            if(rowi <= rowf){
                for(int j=colf;j>=coli;j--){
                    ans.push_back(matrix[rowf][j]);
                }
                rowf--;
            }


            if(coli <= colf){
                for(int i=rowf;i>=rowi;i--){
                    ans.push_back(matrix[i][coli]);
                }
                coli++;
            }
        }

        return ans;
    }
};
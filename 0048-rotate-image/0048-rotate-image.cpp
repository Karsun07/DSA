class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row=matrix.size(),col=matrix[0].size();
        //rotate 90=>transpose+reverse rows
        //traspose
        for(int i=0;i<row;i++){
            for(int j=i+1;j<col;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(auto &arr:matrix){
            reverse(arr.begin(),arr.end());
        }
       
        
        
    }
};
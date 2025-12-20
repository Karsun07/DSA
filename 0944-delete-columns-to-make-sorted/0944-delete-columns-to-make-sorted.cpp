class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int cols=strs[0].size();
        int rows=strs.size();
        int wrong=0;
        for(int j=0;j<cols;j++){
            for(int i=0;i<rows-1;i++){
                if(strs[i][j]-'0'>strs[i+1][j]-'0'){
                    wrong++;
                    break;
                }
            }

        }
        return wrong;
    }
};
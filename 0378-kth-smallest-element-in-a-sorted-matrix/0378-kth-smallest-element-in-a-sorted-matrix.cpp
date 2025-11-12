class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
       
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>p;
        int n=matrix.size();
        for(int i=0;i<n;i++){
            p.push({matrix[i][0],{i,0}});
        }
        int ans=-1;
        while(k--){
            auto x=p.top();
            
            p.pop();
            ans=x.first;
            int i=x.second.first;
            int j=x.second.second;
            if(j+1<n){
                p.push({matrix[i][j+1],{i,j+1}});
            }
        }
        return ans;
    }
};
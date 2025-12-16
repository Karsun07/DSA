class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& inter, vector<int>& newInterval) {
        inter.push_back(newInterval);
        sort(inter.begin() , inter.end());

        vector<vector<int>> ans;
        ans.push_back(inter[0]);
        int n=inter.size();
        int i=1;
        while(i<n){
            if(inter[i][0]>ans.back()[1]){//no over
                ans.push_back(inter[i]);
            }
            else if(inter[i][0]<=ans.back()[1]){
                ans.back()[1]=max(inter[i][1],ans.back()[1]);
            }
            i++;
        }
        return ans;
    }
};
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        int ans=1;
        sort(points.begin(),points.end());
        int target=points[0][1];
        for(int i=1;i<n;i++){
            if(points[i][0]<=target){
                target=min(target,points[i][1]);
            }
            else{
                ans++;
                target=points[i][1];
            }
        }
        return ans;

     
    }
};
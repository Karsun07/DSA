class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
        int n=inter.size();
        sort(inter.begin(),inter.end(),cmp);
        int prev=0,count=1;
        for(int i=1;i<n;i++){
            if(inter[i][0]>=inter[prev][1]){
                //no overlap
                count++;
                prev=i;
            }
        }
        return n-count;
        

    }
};
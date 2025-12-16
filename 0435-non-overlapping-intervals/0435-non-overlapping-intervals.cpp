class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& inter) {
       int n=inter.size();
       sort(inter.begin(),inter.end(),cmp);
       int ending=inter[0][1];
       int ans=0;
       for(int i=1;i<n;i++){
        bool flag=1;//no overalp
        if(inter[i][0]<ending){//overlap
            ans++;
            flag=0;
        }
        if(flag) ending=inter[i][1];
       }
       return ans;

        

    }
};
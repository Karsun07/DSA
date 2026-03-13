class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int r = points.size();
        int c = points[0].size();

        vector<long long> prev(c);

        for(int j=0;j<c;j++)
            prev[j]=points[0][j];

        for(int i=1;i<r;i++){
            vector<long long> left(c), right(c), curr(c);

            left[0]=prev[0];
            for(int j=1;j<c;j++)
                left[j]=max(left[j-1]-1, prev[j]);

            right[c-1]=prev[c-1];
            for(int j=c-2;j>=0;j--)
                right[j]=max(right[j+1]-1, prev[j]);

            for(int j=0;j<c;j++)
                curr[j]=points[i][j]+max(left[j],right[j]);

            prev=curr;
        }

        return *max_element(prev.begin(),prev.end());
    }
};
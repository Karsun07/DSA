class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        int n = points.size();
        double ans = 0.0; 
        
        for (int i=0;i<n-2;i++) {
            double x1=points[i][0],y1 =points[i][1];
            for (int j=i+1;j<n-1;j++) {
                double x2=points[j][0], y2=points[j][1];
                for (int k =j+1;k<n;k++) {
                    double x3 = points[k][0], y3 = points[k][1];
                    double a=hypot(x1-x2,y1-y2);
                    double b=hypot(x1-x3,y1-y3);
                    double c=hypot(x3-x2,y3-y2);

                    double s=(a+b+c)*0.5;

                    double val = s * (s-a)*(s-b)*(s-c);
                    if (val<0) val = 0; 
                    
                    double area = sqrt(val);
                    ans = max(ans, area);
                }
            }
        }
        return ans;
    }
};

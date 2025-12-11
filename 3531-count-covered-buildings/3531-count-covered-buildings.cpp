#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& build) {
       vector<int> minx(n+1, n+1); // min x for a y 
       vector<int> maxx(n+1, 0);   // max x for the same y
       vector<int> miny(n+1, n+1); // min y for a x
       vector<int> maxy(n+1, 0);   // max y for a x
       
       for (int i = 0; i < build.size(); i++) {
         int x = build[i][0], y = build[i][1];
         minx[y] = min(minx[y], x);
         maxx[y] = max(maxx[y], x);
         miny[x] = min(miny[x], y); 
         maxy[x] = max(maxy[x], y);
       }

       int ans = 0;
       for (int i = 0; i < build.size(); i++) {
        int x = build[i][0], y = build[i][1];
        if (x > minx[y] && x < maxx[y] && y > miny[x] && y < maxy[x]) ans++;
       }
       return ans;
    }
};

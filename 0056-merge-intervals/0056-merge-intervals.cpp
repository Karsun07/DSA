class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() < 2) return intervals;

       
        sort(intervals.begin(), intervals.end());

        
        vector<vector<int>> merged;
        merged.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            int& lastEnd = merged.back()[1];

            if (start <= lastEnd) {
                
                lastEnd = max(lastEnd, end);
            } else {
               
                merged.push_back(intervals[i]);
            }
        }

        return merged;
    }
};

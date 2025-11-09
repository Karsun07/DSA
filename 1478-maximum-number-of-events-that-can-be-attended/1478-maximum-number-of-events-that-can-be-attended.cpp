class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int count=0,day=0,i=0,n=events.size();
        priority_queue<int,vector<int>,greater<int>>p;
        while(i<n||!p.empty()){
            if(p.empty()) day=events[i][0];
            while(i<n && events[i][0]==day){
                p.push(events[i][1]);
                i++;
            }
            if(!p.empty()){
                p.pop();
                day++;
                count++;
            }
            while(!p.empty()&& day>p.top()){
                p.pop();

            }
        }
        return count;
        


    }
    
};
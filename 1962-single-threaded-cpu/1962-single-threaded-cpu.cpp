class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
        //sort enque time
        sort(tasks.begin(),tasks.end());
        //min heap=>least process time above 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        long long t=tasks[0][0],i=0;
        vector<int>ans;
        while(i<n||!p.empty()){
            while(i<n && t>=tasks[i][0]){
                p.push({tasks[i][1],tasks[i][2]});
                i++;
            }
            if(p.empty()){
                t=tasks[i][0];
            }
            else{
                auto x=p.top();
                p.pop();
                ans.push_back(x.second);
                t+=x.first;
            }
        }
        return ans;
        
    }
};
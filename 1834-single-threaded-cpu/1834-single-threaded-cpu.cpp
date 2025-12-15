class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n=tasks.size();
        for(int i=0;i<n;i++) tasks[i].push_back(i);
       
        sort(tasks.begin(),tasks.end());
       
        int i=0;
        long long t=tasks[0][0];
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>p;
        while(i<n || !p.empty()){
            while(i<n && t>=tasks[i][0]){
            p.push({tasks[i][1],tasks[i][2]});
            i++;

        }
        if(p.empty()){
            t=tasks[i][0];
        }
        else{
            ans.push_back(p.top().second);
            t+=p.top().first;
            p.pop();

        }
        }
        return ans;
        
    }
};
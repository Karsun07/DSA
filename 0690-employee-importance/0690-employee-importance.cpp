/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        vector<vector<int>>adj(2000);
        vector<int>imp(2000);
        for(auto &it:employees){
            imp[it->id-1]=it->importance;
            for(int sub:it->subordinates){
                adj[it->id-1].push_back(sub-1);
            }
        }
        queue<int>q;
        q.push(id-1);
        int ans=imp[id-1];
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(int nb:adj[node]){
                ans+=imp[nb];
                q.push(nb);
            }
        }
        return ans;
    }
};
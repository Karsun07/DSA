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
        unordered_map<int,Employee*>mp;
        for(auto emp:employees){
           mp[emp->id]=emp;
        }
        queue<int>q;
        q.push(id);
        int ans=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            Employee* e=mp[node];
            ans+=e->importance;
            for(int sub:e->subordinates){
                q.push(sub);
            }
        }
        return ans;

    }
};
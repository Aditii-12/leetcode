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
        for(auto it:employees){
            mp[it->id]=it;
        }
        queue<int>q;
        q.push(id);
        int ans=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            Employee* emp=mp[curr];
            ans+=emp->importance;
            for(auto it:emp->subordinates) q.push(it);
        }
        return ans;
    }
};
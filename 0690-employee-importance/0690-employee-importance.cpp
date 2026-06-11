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
    int dfs(int id,unordered_map<int,Employee*> &mp){
        Employee* emp=mp[id];
        int ans=emp->importance;
        for(auto it:emp->subordinates){
            ans+=dfs(it,mp);
        }
        return ans;
    }
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,Employee*>mp;
        for(auto it:employees){
            mp[it->id]=it;
        }
        return dfs(id,mp);
    }
};
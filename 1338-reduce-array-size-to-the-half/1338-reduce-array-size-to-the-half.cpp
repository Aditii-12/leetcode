class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n=arr.size();
        int m=n;
        unordered_map<int,int>freq;
        for(auto it:arr){
            freq[it]++;
        }
        vector<int>f;
        int ans=0;
        for(auto it:freq) f.push_back(it.second);
        sort(f.rbegin(),f.rend());
        for(auto it:f){
            m-=it;
            ans++;
            if(m<=n/2) return ans;
        }
        return ans;

    }
};
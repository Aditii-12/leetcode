class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numwant, int useLimit) {
        vector<pair<int,int>> items;
        for(int i=0;i<values.size();i++){
            items.push_back({values[i],labels[i]});
        }
        sort(items.rbegin(),items.rend());
        unordered_map<int,int> used;
        int sum=0;
        int taken=0;
        for(auto &[value,label]:items){
            if(used[label]==useLimit)
                continue;
            sum += value;
            used[label]++;
            taken++;
            if(taken == numwant)
                break;
        }
        return sum;
    }
};
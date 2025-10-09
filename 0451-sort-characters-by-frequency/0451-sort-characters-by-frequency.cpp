class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        for (char ch : s) {
            freq[ch]++;
        }
        multimap<int,char,greater<int>>sortedfreq;
        for (auto it : freq) {
        sortedfreq.insert({it.second, it.first}); // (frequency, character)
    }
    string ans="";
    for(auto it:sortedfreq){
        ans.append(it.first,it.second);
    }
    return ans;
    }
};
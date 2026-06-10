class Solution {
public:
    bool isvow(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> firstp;
        //firstpos to store in case of freq is same
        for(int i=0;i<s.size();i++){
            if(isvow(s[i])){
                freq[s[i]]++;
                if(!firstp.count(s[i]))
                firstp[s[i]]=i;
            }
        }
        vector<pair<char,int>>v;
        for(auto it:freq){
            v.push_back(it);
        }
        //{a-5,e-2...}
        sort(v.begin(),v.end(),[&](auto &a, auto &b){
            if(a.second!=b.second)
                return a.second>b.second;
            return firstp[a.first]<firstp[b.first];
        });
        string vowels="";
        for(auto &it:v){
            vowels.append(it.second,it.first);
        }
        int j=0; //pointer for string of vowels

        for(int i=0;i<s.size();i++){
            if(isvow(s[i])){
                s[i]=vowels[j++];
            }
        }
        return s;
    }
};
class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int add) {
        int n=capacity.size();
        vector<int> diff(n);
        for(int i=0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        int count=0;
        sort(diff.begin(),diff.end());
        for(int i=0;i<n;i++){
            if(diff[i]<=add){
                count++;
                add-=diff[i];
            }
            else break;
        }
        return count;
    }
};
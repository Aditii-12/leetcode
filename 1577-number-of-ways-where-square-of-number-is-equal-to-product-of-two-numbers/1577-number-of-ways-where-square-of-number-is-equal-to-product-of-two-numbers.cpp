class Solution {
public:
    long long func(vector<int>& a,vector<int>& b){
        unordered_map<long long,long long>freq;
        for(int x:b) freq[x]++;
        long long ans=0;
        for(int x:a){ //in a
            long long t=1LL*x*x;
            for(auto &[aa,cnt]:freq){ //for vector b
                if(t%aa!=0) continue;
                long long bb=t/aa;
                if(!freq.count(bb)) continue;
                if (bb<aa) continue; //ek br hi count krne k liye
                if(aa==bb){
                    ans+=(cnt)*(cnt-1)/2;
                }
                else{
                    ans+=(cnt)*freq[bb];
                }
            }
        }
        return ans;
    }
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        return func(nums1,nums2)+func(nums2,nums1);
    }
};
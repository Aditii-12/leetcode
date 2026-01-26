class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>pos,val;
        for(int i=0;i<n;i++){
            if(nums[i]>=0){
                pos.push_back(i);
                val.push_back(nums[i]);
            }
        }
        if(pos.size()==0) return nums;
        k=k%pos.size(); //faltu ke rotations ni honge
        vector<int>rot;
        for(int i=k;i<val.size();i++){
            rot.push_back(val[i]); //k se lekr end tk starting me ajayenge
        }
        for(int i=0;i<k;i++){
            rot.push_back(val[i]);//starting se lekr k tk uske bd ayenge
        }
        for(int i=0;i<pos.size();i++){
            nums[pos[i]]=rot[i];
        }
        return nums;
    }
};
class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        bool f=1;
        int temp;
        for(int i=0;i<nums.size();i++){
            if(f==1 && nums[i]==1){
                f=0;  //jese hi ek one mila to f lock krdiya
                //more like semaphore 
                temp=i; //ye index store krlia ki last 1 kaha mila tha
                continue;
            }
            if(nums[i]==1){ //jb nya 1 milega
            //to we will calculate distance
            //i-temp-1 agr k se bda ya equal  hua to shi h
            //now is 1 ki index store krlenge in temp
                if(i-temp-1>=k) temp=i;
                else return 0;
            }
        }
        return 1;
    }
};
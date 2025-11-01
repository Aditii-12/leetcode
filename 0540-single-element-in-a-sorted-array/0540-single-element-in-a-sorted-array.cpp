class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        // cutting edge cases so we can start with 1 to n-2
        if (nums[0] != nums[1])
            return nums[0];
        if (nums[n - 2] != nums[n - 1])
            return nums[n - 1];
        int low = 0;
        int high = n - 2;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
                return nums[mid];
            }
            // mid is on odd index, pair exist in (even,odd) index like
            //(0,1) (2,3) then when single element comes it will be on odd index
            // then order will change
            //(0,1) (2,3) (5) (6,7) (7,8)
            // 1 1.  4.4.  6.  7,7.   9,9
            // pehle pairs was on index(even,odd) when single element occured
            // then it changes to (odd,even)
            else if ((mid % 2 == 1 && nums[mid - 1] == nums[mid]) ||
                     (mid % 2 == 0 &&nums[mid] ==nums[mid + 1])) 
                     //means single element right side h
                     //and abi tk vhi sequence chlra h (even,odd)
            {
                low = mid + 1;
            }
            else high=mid-1;
        }
        return 0;
    }
};
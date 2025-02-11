class Solution {
public:
    int solve(vector<int>& nums, int len, int target){
        int left=0;
        int right=len-1;
        while(left<=right)
        {
            int midele= left+(right-left)/2;
            if(nums[midele]==target)
              return midele;
            else if (nums[midele]< target)
                    left=midele+1;
            else
                right=midele-1;
        }
        return left;
    }
    int searchInsert(vector<int>& nums, int target) {
        int n= nums.size();
        return solve(nums,n, target);
    }
};
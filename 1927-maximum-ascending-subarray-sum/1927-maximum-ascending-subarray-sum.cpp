class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n= nums.size();
        int maxSum= INT_MIN;
        int currSum=nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]<nums[i])
                currSum+=nums[i];
            else
            { 
               maxSum=max(maxSum,currSum);
               currSum=nums[i];
            }
        }
        maxSum=max(maxSum,currSum);
        return maxSum;
    }
};
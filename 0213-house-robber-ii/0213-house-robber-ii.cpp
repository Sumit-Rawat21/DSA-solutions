class Solution {
public:
    int solve(int indx, vector<int> &nums){
        int n= nums.size();
        vector<int> res(n);
        res[0]=nums[0];
        for(int i=1;i<n; i++){

        int pick= (i==1) ?nums[i]:nums[i]+res[i-2];
        int notpick= 0+res[i-1];
        res[i]=max(pick,notpick);
        }
        
    return res[n-1];
    }

    int rob(vector<int>& nums) {
       vector<int> temp1;
       vector<int> temp2;
       int n=nums.size();
       if(n ==1) return nums[n-1];
       for(int i=0;i<n;i++){
        if(i !=0) temp1.push_back(nums[i]);
        if(i !=n-1 ) temp2.push_back(nums[i]);
       }
       return max(solve(temp1.size()-1, temp1), solve(temp2.size()-1, temp2));
    }
};
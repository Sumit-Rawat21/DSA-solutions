class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
                unordered_map<int,int> countDistinct;
                for(int x:nums){
                    countDistinct[x]++;
                }
                int dstnctEle= countDistinct.size();
                int res=0;

            for(int i=0;i<nums.size(); i++){
                map<int,int> tempDistinct;
                vector<int> completeSubarray;
                for(int j=i;j<nums.size();j++){
                    completeSubarray.push_back(nums[j]);
                    tempDistinct[nums[j]]++;                       
                    if(tempDistinct.size()==dstnctEle)
                        res++;
                }
            }
            return res;

    }
};
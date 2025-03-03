class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
       int lesser=0; int equall=0; vector<int> result(n);
       for(int i: nums)
       {
        if(i<pivot) lesser++;
        if(i==pivot) equall++;
       }
    int i=0; int j= lesser; int k= lesser+equall;
    for(int n:nums){
        if(n<pivot){
            result[i++]=n;
        }
        if(n==pivot) result[j++]=n;
        if(n>pivot) result[k++]=n;
    } 
       return result;
    }
};
class Solution {
public:
    long long coloredCells(int n) {
        vector<long long> res(n);
        res[0]=1;
        for(long long i=1;i<n;i++){
            res[i]=(4*i)+res[i-1];
        }
        return res[n-1];
    }
};
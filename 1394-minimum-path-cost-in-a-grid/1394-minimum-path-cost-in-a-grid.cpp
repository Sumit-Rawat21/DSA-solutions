class Solution {
public:
    int solve(int i, int j,int m, int n, vector<vector<int>> &grid, vector<vector<int>> &moveCost, vector<vector<int>> &dp){
        if(i == m-1 ) return grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        for(int k=0; k<n; k++){
            res=min(res,grid[i][j] + moveCost[grid[i][j]][k]+ solve(i+1,k,m,n,grid,moveCost,dp));
        }
        return dp[i][j]=res;
    }

    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m= grid.size();
        int n=grid[0].size();
        cout<<m <<","<<n;
        int res=INT_MAX;
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        for(int j=0;j<n;j++){
           res=min(res,solve(0,j,m,n, grid, moveCost,dp)); 
        }
        return res;
    }
};
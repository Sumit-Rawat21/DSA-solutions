class Solution {
public:
    int modulo = 1e9 + 7;
    
    int solve(int m, int n, int maxMove, int row, int col, vector<vector<vector<int>>> &dp) {
        // Ball moves out of the grid -> 1 valid path
        if (row < 0 || col < 0 || row >= m || col >= n) return 1;
        // No moves left -> No valid path
        if (maxMove == 0) return 0;
        // Return if already computed
        if (dp[row][col][maxMove] != -1) return dp[row][col][maxMove];

        int way1 = solve(m, n, maxMove - 1, row - 1, col, dp);
        int way2 = solve(m, n, maxMove - 1, row + 1, col, dp);
        int way3 = solve(m, n, maxMove - 1, row, col - 1, dp);
        int way4 = solve(m, n, maxMove - 1, row, col + 1, dp);

        // Store result in DP table
        return dp[row][col][maxMove] = ((way1 + way2) % modulo + (way3 + way4) % modulo) % modulo;
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove + 1, -1)));
        return solve(m, n, maxMove, startRow, startColumn, dp);
    }
};
class Solution {
public:
    int solve(vector<vector<int>> grid , int i , int j , vector<vector<int>>&dp){
        int n =grid.size();
        int m =grid[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)return INT_MAX;
        if(i == n-1 && j == m-1)return grid[i][j]; 
        if(dp[i][j] != -1 ) return dp[i][j];
        int down = solve(grid , i+1 , j ,dp);
        int right =solve(grid , i , j+1, dp);
        return dp[i][j] =grid[i][j] + min(down , right);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m =grid.size();
        int n =grid[0].size();
        vector<vector<int>> dp(m , vector<int>(n , -1));
        return solve(grid, 0 , 0 , dp);
    }
};
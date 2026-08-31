class Solution {
public:
    int solve(vector<vector<int>> &mat , int i, int j ,  vector<vector<int>>&dp){
        int n = mat.size();
        int m = mat[0].size();
        if(i < 0 || j  <0 || i >= n || j >= m || mat[i][j] == 1) return 0;
        if(i == n -1 && j == m-1) return 1;
        if(dp[i][j] != -1)return dp[i][j];
        int ans = solve(mat , i +1 , j , dp) + solve(mat , i , j+1 , dp);
        return dp[i][j] = ans;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n , vector<int>(m , -1));
        return solve(obstacleGrid , 0 , 0 , dp);
    }
};
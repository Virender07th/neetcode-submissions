class Solution {
public:
    int solve(int amount, vector<int>&coins , int i ,  vector<vector<int>>&dp){
        if(i >= coins.size() || amount < 0) return 0;
        if(amount == 0 )return 1;
        if(dp[i][amount] != -1 )return dp[i][amount];
        int take = 0;
        if(coins[i] <= amount) take = solve(amount - coins[i] , coins , i , dp);
        int nt = solve(amount , coins , i+1 , dp);
        return dp[i][amount] = take + nt;
    }
    int change(int amount, vector<int>& coins) {
        int n =coins.size();
        vector<vector<int>> dp(n , vector<int>(amount +1 , -1));
        return solve(amount , coins , 0 , dp);
    }
};

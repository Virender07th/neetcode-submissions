class Solution {
public:
    int solve(string s , string t , int i , int j ,vector<vector<int>>&dp){
        int n =s.size();
        if(i == n || j == n) return 0;
        if(dp[i][j] != 0) return dp[i][j];
        if(s[i] == t[j]) return dp[i][j] = 1 +solve(s , t , i +1 , j+1 , dp);
        return dp[i][j] = max(solve(s, t , i+1 , j , dp ) , solve(s, t, i , j+1, dp));
    }
    int longestPalindromeSubseq(string s) {
        string t =s;
        int n =t.size();
        reverse(t.begin() , t.end());
        vector<vector<int>> dp(n +1 , vector<int>(n +1 , 0));

        for(int i = n-1; i >= 0 ;i-- ){
            for(int j = n -1 ; j >= 0 ; j--){
                if(s[i] == t[j]){
                    dp[i][j] =1+ dp[i+1][j+1];
                }else dp[i][j] = max(dp[i+1][j] , dp[i][j+1]); 
            }
        }
        return solve(s, t , 0 , 0 , dp);
    }
};
class Solution {
public:
    int solve(int i,int j,int m,int n,vector<vector<int>> &dp){   
        // if we go out of bounds then return 0
        if(i>=m||j>=n)
            return 0;
        // reached the target so return 1
        if(i==m-1&&j==n-1)
            return 1;
        // if already memoized then return stored result;
        if(dp[i][j]!=-1)
            return dp[i][j];
        // store the result for down and right blocks
        dp[i][j]=solve(i+1,j,m,n,dp)+solve(i,j+1,m,n,dp);
        // return ans
        return dp[i][j];
    }
    int uniquePaths(int m, int n) {
        //dp array for memoization
        vector<vector<int>> dp(m,vector<int>(n,-1));
        // call helper func
        return solve(0,0,m,n,dp);
    }
};
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size(), m=word2.size();
        // dp of n+1,m+1 size
        vector<vector<int>> dp(n+1,vector<int> (m+1));
        //initialize last row
        for(int j=0;j<=m;j++){
            dp[n][j] = m-j;
        }
        // init last col
        for(int i=0;i<=n;i++){
            dp[i][m] = n-i;
        }
        // start from bottom right
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                //if char are same copy diagonal val
                if(word1[i]==word2[j])
                    dp[i][j] = dp[i+1][j+1];
                //min of right,down,diagonal + 1
                else
                    dp[i][j] = 1 + min({dp[i][j+1],dp[i+1][j],dp[i+1][j+1]});
            }
        }
        // result will be stored in 0 0 
        return dp[0][0];
    }
};

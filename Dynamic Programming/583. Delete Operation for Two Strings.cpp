class Solution {
public:
    // If we can find this lcs value, we can easily determine the required result 
    // as m + n - 2*lcs
    // The above equation works because in case of complete mismatch
    // (i.e. if the two strings can't be equalized at all), 
    // the total number of delete operations required will be m + n. 
    // Now, if there is a common sequence among the two strings of length lcs,
    // we need to do lcslcs lesser deletions in both the strings leading to a total 
    // of 2lcs lesser deletions, which then leads to the above equation.
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(word1[i] == word2[j])
                    dp[i][j] = 1+dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
            }
        }
        
        int lcs = dp[0][0];
        return m+n - (2*lcs);
    }
};
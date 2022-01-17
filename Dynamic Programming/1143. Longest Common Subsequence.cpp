class Solution {
public:
    //this is bottom up approach
    //if the chars match we move diagonally
    //if they don't then we move right or down
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m=text2.size();
        //need 1 more row and col to start off
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        //traverse in reverse
        for(int i=n-1;i>=0;i--){
            for(int j=m-1; j>=0; j--){
                //if the curr char are equal
                if(text1[i] == text2[j])
                    //we increase the subsequence size by 1
                    dp[i][j] = 1 + dp[i+1][j+1]; 
                    //if they do not match copy the max value out of
                    //right/down cell
                else
                    dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
            }
        }
        return dp[0][0];
    }
};

//top-down approach
// int longestCommonSubsequence(string &a, string &b) {
//   vector<vector<short>> m(a.size() + 1, vector<short>(b.size() + 1));
//   for (auto i = 1; i <= a.size(); ++i)
//     for (auto j = 1; j <= b.size(); ++j)
//       if (a[i - 1] == b[j - 1]) m[i][j] = m[i - 1][j - 1] + 1;
//       else m[i][j] = max(m[i - 1][j], m[i][j - 1]);
//   return m[a.size()][b.size()];
// }
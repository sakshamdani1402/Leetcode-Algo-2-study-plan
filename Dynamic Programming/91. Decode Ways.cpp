class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        //dp array n+1 size 
        vector<int> dp(n+1,0);
        //to start off
        dp[n]=1;
        //traverse in reverse
        for(int i=n-1;i>=0;i--){
            // if this is 1 digit number
            if(s[i]!='0')
                dp[i]+=dp[i+1];
            // we have numbers ahead with which we can work (for 2 digit nos)
            //if this digit is 1 or (it is 2 and next digit is <=6)
            if(i+1<n and (s[i]=='1' or (s[i]=='2' and s[i+1] <'7')))
                dp[i]+=dp[i+2];
        }
        //ans will be stored at 0th index
        return dp[0];
    }
};
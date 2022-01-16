class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        //dp array
        vector<bool> dp(n+1,false);
        //we need a starting value
        dp[n]=true;
        //start in reverse
        for(int i=n-1;i>=0;i--){
            //iterate thru the dictionary
            for(auto word:wordDict){
                //if the len of the word from curr index is less than n
                //then a word can be matched
                //now we take the substr and match it with the dict word
                if(i+word.size()<=n && s.substr(i,word.size()) == word)
                    //if it matches we store the val of dp[index where word ends]
                    dp[i] = dp[i+word.size()];
                //we already have found the word so search next word
                if(dp[i])
                    break;
            }
        }
        //the result will be stored in dp[0]
        return dp[0];
    }
};

//      l e e t c o d e
//      0 1 2 3 4 5 6 7 8
//      t f f f t f f f t <-starting true val at index 8

// when we reach index 4 we have substr 'code' which get matched in dict
//so we store the val of dp[i+word len] which is indeed the word break point
// 4 <- 8
// 0 <- 4
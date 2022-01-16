class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        //we need an array to store length and an array to store counts
        //so why not use a pair in a single vector array
        //first -> length of subsequence
        //second ->count
        vector<pair<int,int>> dp(n,{1,1});
        //the min len of a subsequence can be 1 [for single elem]
        int maxLen=1;
        //iterate in reverse
        for(int i=n-1;i>=0;i--){
            //from curr elem to start
            for(int j=i+1;j<n;j++){
                //only executed if subsequence is increasing
                if(nums[i]<nums[j]){
                    // if the subsequence len > curr subsequence len
                    if(dp[j].first+1>dp[i].first)
                        //setting len and count at the same time
                        dp[i] = {dp[j].first+1,dp[j].second};
                    // if the len is same     
                    else if(dp[i].first == 1 + dp[j].first)
                        dp[i].second+=dp[j].second;
                }
            }
            //update the maxlen
            maxLen = max(maxLen,dp[i].first);
        }
        //to count the no of subsequences of maxLen
        int count=0;
        for(auto num:dp){
            if(num.first==maxLen)
                count+=num.second;
                
        }
        return count;
    }
};
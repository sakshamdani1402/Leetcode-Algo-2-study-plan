class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        //cache table
        vector<int> dp(n,1);
        // traverse in reverse
        for(int i=n-1;i>=0;i--){
            // for curr elem find the LIS
            //traverse in normal way
            for(int j = i+1;j<n;j++){
                //only do this if curr elem < jth elem
                if(nums[i] < nums[j])
                    dp[i] = max(dp[i],1+dp[j]);
            }
        }
        //find the max elem in the dp vector
        //max_element returns iterator so * dereferences it
        return *max_element(dp.begin(),dp.end());
    }
};
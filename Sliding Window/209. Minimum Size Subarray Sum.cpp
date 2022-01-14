class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        // since all nums are positive target cannot be <=0
        // thus we return 0 no such subarray can exist
        if(target<=0) return 0;
        
        int minLen=INT_MAX,sum=0;
        int left=0;
        
        // iterate till right reaches last elem
        for(int right=0;right<nums.size();right++){
            // increment sum
            sum+=nums[right];
            // this will run when the sum becomes greater or equal to
            // target as we now want to find the next subarray 
            // with sum>=target and store the min len as we move the left
            // ptr forward untill sum becomes less than target
            while(sum>=target){
                minLen=min(minLen,(right-left)+1);
                sum-=nums[left];
                left++;
            }
        }
        // there is a possibility that we dont find any subarray
        // then minlen would be untouched 
        // so we return 0 if such is the case else we simply return 
        // the minLen
        return minLen==INT_MAX ? 0:minLen;
    }
};
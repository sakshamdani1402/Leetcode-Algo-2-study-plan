class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach=0;
        //iterate
        for(int i=0;i<n;i++){
            //if we reach a index further than we could reach return false
            if(i>maxReach) return false;
            //set max reach
            maxReach = max(i+nums[i],maxReach);
        }
        //we have reached the end so return true
        return true;
    }
};
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        int maxReach=0,currEnd=0,jumps=0;
        for(int i=0;i<n-1;i++){
            //store max reachable index currently
            maxReach = max(maxReach,nums[i]+i);
            //we have reached the end of jump
            if(currEnd == i){
                //take next jump
                jumps++;
                //next end will be max reachable index
                currEnd=maxReach;
            }
        }
        return jumps;
    }
};
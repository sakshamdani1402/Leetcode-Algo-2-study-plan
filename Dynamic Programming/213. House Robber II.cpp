class Solution {
public:
    // since houses are in a circle so 1st and last house is adjacent
    // so we can rob only one of them
    // therefore we rob from 1st to 2nd last house
    // or we rob 2nd to last house
    // and return the max out of both of them
    int rob(vector<int>& nums) {
        int n= nums.size();
        //if nums is empty we cant rob house
        if(n==0) return 0;
        //if only 1 house its the only amount we can rob
        if(n==1) return nums[0];
                        //1st - 2nd last         2nd - last 
        return max(robHouse(nums,0,n-2),robHouse(nums,1,n-1));
    }
    int robHouse(vector<int>& nums, int start, int end){
        // curr = current sum
        // prev = sum 2 spaces behind
        int prev=0,curr=0,maxNow;
        for(int i=start;i<=end;i++){
            // for the current index max is curr or ith elem + prev
            maxNow = max(prev+nums[i],curr);
            //set for the next iterations
            prev = curr;    //prev will become curr
            curr = maxNow;     //curr will become max till now
        }
        // at last index curr will be maxNow
        return curr;
    }
};
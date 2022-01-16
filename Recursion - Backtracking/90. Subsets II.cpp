class Solution {
public:
    // declare as class variable so we dont have to pass them as param
    vector<vector<int>> powerSet;
    vector<int> subSet;
    // input size
    int n;
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // init with input size
        n=nums.size();
        // sort to skip duplicates
        sort(nums.begin(),nums.end());
        // start backtrackibg with curr index
        backtrack(nums,0);
        return powerSet;
    }
    
    void backtrack(vector<int>& nums, int curr){
        // push curr subset into the power set
        powerSet.push_back(subSet);
        // start iterating over nums
        for(int i=curr;i<n;i++){
            // only run if it is at curr index or isnt a duplicate
            if(i==curr || nums[i] != nums[i-1]){
                subSet.push_back(nums[i]);
                backtrack(nums,i+1);
                // pop the elem after backtracking it
                subSet.pop_back();
            }
        }
    }
};
class Solution {
public:
    //defining global variables so we dont have to
    //pass them as params
    vector<vector<int>> powerSet;
    vector<int> subSet;
    //size of the input
    int n;
    
    vector<vector<int>> subsets(vector<int>& nums) {
        // set input size
        n=nums.size();
        // call dfs from 0th index
        dfs(nums,0);
        return powerSet;
    }
    
            //          input , curr idx
    void dfs(vector<int>& nums,int curr){
        //we want all possible subsets so we push
        //every time dfs is called
        powerSet.push_back(subSet);
        //for all elem in nums
        for(int i=curr;i<n;i++){
            //push curr elem
            subSet.push_back(nums[i]);
            //call dfs for the next index
            dfs(nums,i+1);
            //backtrack
            subSet.pop_back();
        }
    }
};
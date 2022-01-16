class Solution {
public:
    //class variables so that we dont have to pass them as params
    vector<vector<int>> res;
    vector<int> combi;
    int n,sum=0;
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        n = candidates.size();
        backtrack(candidates,target,0);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int target, int curr){
        // base case, if we exceed the target, we dont need the curr elem
        // so return and move on
        if(sum>target) return;
        // here we found a soln so add it to result and return;
        if(sum==target){
            res.push_back(combi);
            return;
        }
        
        for(int i=curr;i<n;i++){
            sum+=candidates[i];                 //add current value to sum
            combi.push_back(candidates[i]);     //add current value to current vector
            backtrack(candidates,target,i);     //backtrack for same index i cuz a elem can be included infinite times
            sum-=candidates[i];                 //remove the curr elem and continue for next elem
            combi.pop_back();                   //remove the curr elem from combinations
            
        }
    }
};
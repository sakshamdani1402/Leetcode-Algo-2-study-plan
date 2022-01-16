class Solution {
public:
    vector<vector<int>> res;
    vector<int> combi;
    int n,sum;
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        n=candidates.size();
        sum=0;
        sort(candidates.begin(),candidates.end());
        backtrack(candidates,target,0);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int target, int curr){
        if(sum>target) return;
        if(sum==target){
            res.push_back(combi);
            return;
        }
        
        for(int i=curr;i<n;i++){
            //to avoid duplicates we skip the elem if it is same as prev
            if(i!=curr && candidates[i] == candidates[i-1]) 
                continue;
            sum+=candidates[i];
            combi.push_back(candidates[i]);
            backtrack(candidates,target,i+1);
            sum-=candidates[i];
            combi.pop_back();
        }
    }
};
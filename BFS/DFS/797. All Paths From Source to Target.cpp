class Solution {
public:
    //class variables so that we dont have to pass these as parameters
    //again and again
    int target;
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<vector<int>>& g,int curr){
        //if we have reached target we have found a path so push in res vector
        //end this dfs recursion
        if(curr == target){
            res.push_back(path);
            return;
        }
        //we still havent reached the end
        else{
            // for a node in current position
            for(auto node : g[curr]){
                path.push_back(node);
                dfs(g,node);
                path.pop_back();
            }
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& g) {
        //given
        target=g.size()-1;
        //to start 
        path.push_back(0);
        dfs(g,0);
        return res;
    }
};
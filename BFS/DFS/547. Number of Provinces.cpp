class Solution {
public:
    void dfs(vector<vector<int>> &isConnected,vector<bool> &seen, int i){
        int m = isConnected[0].size();
        seen[i]=true;
        for(int j=0;j<m;j++){
            if(isConnected[i][j]==1 and !seen[j]){
                dfs(isConnected,seen,j);
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        if(isConnected.empty()) return 0;
        int provinces=0,n=isConnected.size();
        vector<bool> seen(n,false);
        for(int i=0;i<n;i++){
            if(!seen[i]){
                dfs(isConnected,seen,i);
                provinces++;
            }
        }
        return provinces;
    }
};
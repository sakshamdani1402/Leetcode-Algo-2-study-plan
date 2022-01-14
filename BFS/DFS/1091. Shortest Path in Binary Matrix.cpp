class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();
        // we want to traverse the matrix where the elem is zero
        // if the origin or target isnt zero, we simply return
        if(grid[0][0] != 0 || grid[r-1][c-1] != 0) 
            return -1;
        //queue to store coordinates
        queue<pair<int,int>> q;
        //push coordinates of origin
        q.push({0,0});
        // set its value to 1 to mar it visited
        grid[0][0]=1;
        // directions of all 8 adjacent cells
        vector<vector<int>> directions = {
            {0,1},{0,-1},{1,0},{-1,0},
            {-1,-1},{-1,1},{1,-1},{1,1}
        };
        
        while(!q.empty()){
            // get the current coordinates
            pair<int,int> curr = q.front();
            int x = curr.first;
            int y = curr.second;
            // if the current pair is the target cell we return its value
            // that is its distance form the origin
            if(x==r-1 && y==c-1)
                    return grid[x][y];
            // dequeue the elem
            q.pop();
            // to check in all 8 directions of the current cell
            for(auto d:directions){
                int row = x + d[0];
                int col = y + d[1];
                // if all is well
                if(row>=0 && row<r && col>=0 && col<c && grid[row][col]==0){
                    // push the directionally adjacent cell in the queue
                    // to check its respective adjacent cells in future
                    q.push({row,col});
                    // set its value to curr elems distance +1
                    // this also acts as memoization if its visited or not
                    grid[row][col]= grid[x][y]+1;
                }
            }
        }
        // if not possible
        return -1;
    }
};
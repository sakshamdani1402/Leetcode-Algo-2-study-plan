class Solution {
public:
    // utility dfs func
    void dfs(vector<vector<char>>& board, int i, int j){
        int rows=board.size(), cols=board[0].size();
        // if elem is out of bounds or is not O return
        if(i<0 or j<0 or i>=rows or j>=cols or board[i][j]!='O')
            return;
        // here this elem O and is boundary elem or is reachable from the boundary
        // so mark it as visited
        board[i][j]='#';
        // run dfs on curr elem to find further reachable O's
        dfs(board,i-1,j);
        dfs(board,i+1,j);
        dfs(board,i,j-1);
        dfs(board,i,j+1);
    }
    
    // we will use boundary dfs i.e. dfs from boundary elem to inward elem
    
    void solve(vector<vector<char>>& board) {
        int rows=board.size(), cols=board[0].size();
        // iterate thru the board
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                // if elem is O and is boundary elem then run dfs
                if(board[i][j]=='O' && (i==0 or j==0 or i==rows-1 or j==cols-1))
                    dfs(board,i,j);
            }
        }
        
        // we have successfully turned O's which are bounday elem or are reachable
        // to '#'. now the O's which arent reachable and thus are surrounded are left
        // change  #->O and O->X to obtain desired board
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(board[i][j]=='#')
                    board[i][j]='O';
                else if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
    }
};
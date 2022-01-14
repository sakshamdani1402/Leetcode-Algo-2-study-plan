class Solution:
    def dfs(self,g: List[List[str]],i:int,j:int):
        # return if i,j is less or greater than 0 or size respectively
        if(i<0 or j<0 or i>=len(g) or j>=len(g[0]) or g[i][j]!='1'):
            return
        
        # since this is a valid elem to mark this visited we just change
        # its value to '#' though it could be anything
        g[i][j]='#'
        
        # now call dfs in all 4 directions of this cell
        self.dfs(g,i-1,j)
        self.dfs(g,i+1,j)
        self.dfs(g,i,j-1)
        self.dfs(g,i,j+1)
        
        # we aren't returning anything we just changing the original grid
        # to check if the node is visited or not
        
    def numIslands(self, grid: List[List[str]]) -> int:
        # if grid is empty we cannot have islands so return 0
        if not grid : return 0
        islands=0
        # traverse the grid
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                # run dfs if elem is 1 and increment island count
                if grid[i][j] == '1':
                    self.dfs(grid,i,j)
                    islands+=1
            
        return islands
        
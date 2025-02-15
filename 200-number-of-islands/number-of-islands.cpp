class Solution {
public:

    int numIslands(vector<vector<char>>& grid) {
       if(grid.size()==0 || grid[0].size()==0){
        return 0;
       }
        int ctr=0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]=='1'){
                ctr++;
                dfs(grid,i,j);
            }
        }
       }
       return ctr;
    }
private:
    void dfs(vector<vector<char>>&grid,int i,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]!='1'){
            return;
        } 
        grid[i][j]='0'; //mark particular element as visited
        dfs(grid,i+1,j); //down
        dfs(grid,i-1,j); //up
        dfs(grid,i,j+1); // right
        dfs(grid,i,j-1); //left
    }
};

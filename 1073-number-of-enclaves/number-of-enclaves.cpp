class Solution {
public:
    void bfs(vector<vector<int>>&grid,int i, int j){
        queue<pair<int,int>>q;
        q.push({i,j});
        vector<pair<int,int>>dirs= {{1,0},{-1,0},{0,1},{0,-1}};
        grid[i][j]=-1;
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();

            for(auto dir:dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;

                if(nx>=0 && nx<grid.size() && ny>=0 && ny<grid[0].size() && grid[nx][ny]==1){
                    grid[nx][ny]=-1;
                    q.push({nx,ny});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int ctr=0;
       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if((i==0 || i==grid.size()-1 || j==0 || j==grid[0].size()-1)&& grid[i][j]==1){
                bfs(grid,i,j);
            }
        }
       }

       for(int i=0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]==1){
                ctr++;
            }
        }
       }
       return ctr;
    }
};
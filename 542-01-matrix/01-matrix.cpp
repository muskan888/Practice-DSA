class Solution {
public:
    void bfs(vector<vector<int>>&mat,vector<vector<int>>&distance,queue<pair<int,int>>&q){
        vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        while(!q.empty()){
            auto[x,y]=q.front();
            q.pop();
            for(auto dir:dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;
                //if neighbors are either out of bound or already visited-> do nothing
                if(nx<0 || nx>=mat.size() || ny<0 || ny>=mat[0].size() || distance[nx][ny]!=-1){
                    continue;
                }
                else{
                    distance[nx][ny]=distance[x][y]+1;
                    q.push({nx,ny});
                }
            }
        }

    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        queue<pair<int,int>>q;
        vector<vector<int>> distance(mat.size(),vector<int>(mat[0].size(),-1));
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==0){
                    q.push({i,j});
                    distance[i][j]=0;
                }
            }

        }
        bfs(mat,distance,q);
        return distance;
    }
};
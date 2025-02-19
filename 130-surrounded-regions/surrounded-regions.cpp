class Solution {
public:
   void bfs(vector<vector<char>>&board,int x,int y ){
        queue<pair<int,int>>q;
        q.push({x,y});
        vector<pair<int,int>>dirs={{1,0},{-1,0},{0,1},{0,-1}};
        board[x][y]='S';
        while(!q.empty()){
            auto [x,y]=q.front();
            q.pop();
            for(auto dir:dirs){
                int nx=x+dir.first;
                int ny=y+dir.second;
                if(nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size() && board[nx][ny] == 'O'){
                    
                if(board[nx][ny]=='O'){
                    board[nx][ny]='S';
                    q.push({nx,ny});

                }

                
                }
            }
        }

    }
    void solve(vector<vector<char>>& board) {
        
        //marking all the border ones and O's connected to that as 'S'
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1) && board[i][j]=='O'){
                    bfs(board,i,j);
                }
            }
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                 if(board[i][j]=='S'){
                    board[i][j]='O';
                }
            }
        }

        
    }
};
class Solution {
public:
    void dfs(vector<vector<int>>& isConnected,int ele,vector<bool>&visited){
        visited[ele]=1;
        for(int j=0;j<isConnected[ele].size();j++){
            
            if(isConnected[ele][j]==1&&!visited[j]){
                dfs(isConnected,j,visited);

            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),0);
        int ctr=0;
        for(int i=0;i<isConnected.size();i++){
            if(!visited[i]){
                ctr++;
                dfs(isConnected,i,visited);
            }
        }
        return ctr;
        
    }
};
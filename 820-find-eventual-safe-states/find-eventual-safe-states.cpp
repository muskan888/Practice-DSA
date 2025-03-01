class Solution {
public:
//fn to detect cycle
    bool dfs(int node, vector<vector<int>>&graph,vector<int>&visited,vector<int>&pathVisited,vector<int>&safe){
        visited[node]=1;
        pathVisited[node]=1;
        
        for(auto neighbor:graph[node]){
            if(!visited[neighbor]){
                if(dfs(neighbor,graph,visited,pathVisited,safe)){
                    safe[node]=0;
                    return true;
                }
               
            }
             else if(pathVisited[neighbor]){
                safe[node]=0;
                return true;
             }
        }
        safe[node]=1;
        pathVisited[node]=0;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(),0);
        vector<int>pathVisited(graph.size(),0);
        vector<int>safe(graph.size(),0);

        for(int i=0;i<graph.size();i++){
            if(!visited[i]){
                if(!dfs(i,graph,visited,pathVisited,safe)){
                    safe[i]=1;
                }
            }
        }
        vector<int>ans;
        for(int i=0;i<safe.size();i++){
            if(safe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
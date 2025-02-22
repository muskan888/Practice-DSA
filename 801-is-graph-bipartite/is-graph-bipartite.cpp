class Solution {
public:
    bool bfs(vector<vector<int>>&graph,int node,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int i=0;i<graph[curr].size();i++){
                if(color[graph[curr][i]]==color[curr]){
                    return false;
                }
               if(color[graph[curr][i]]==-1){
                 color[graph[curr][i]]=1-color[curr]; //if curr color is 0-> adj color=1, if 1 adj=0;
                q.push(graph[curr][i]);
                
               }

            }
        }
        return true;
        

    }
    bool dfs(vector<vector<int>>&graph, int node, vector<int>&color, int currColor){
        if(color[node]!=-1){
            return color[node]==currColor;
        }
        color[node]=currColor;
        for(int i=0;i<graph[node].size();i++){
           if(! dfs(graph,graph[node][i],color,1-currColor)){
            return false;
           }
        }
        return true;

    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>color(graph.size(),-1);
        //graph can be disconnected so we check for every node
        for(int i=0;i<color.size();i++){
            if(color[i]==-1){
                //this covers every starting node
                // if(!bfs(graph,i,color)){
                //     return false;
                // }
                if(!dfs(graph,i,color,0)){
                    return false;
                }
            }
        }
        return true;
    }
};
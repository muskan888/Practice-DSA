class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int oldColor,int color){
        if(sr<0 || sr>=image.size() || sc<0 || sc>image.size() || image[sr][sc]!=oldColor){
            return;
        }
        image[sr][sc]=color;
        dfs(image,sr+1,sc,oldColor,color); //down
        dfs(image,sr-1,sc,oldColor,color); //up
        dfs(image,sr,sc+1,oldColor,color); //right
        dfs(image,sr,sc-1,oldColor,color); //left

    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldColor=image[sr][sc];

        if(oldColor!=color){
            dfs(image,sr,sc,oldColor,color);
        }
        return image;
    }
};
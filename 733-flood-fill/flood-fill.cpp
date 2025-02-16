class Solution {
public:
    void dfs(vector<vector<int>>& image, int x, int y,int oldClr, int newClr){
        int row = image.size();
        int col = image[0].size();

        if(x<0 || y<0 || x>=row || y>= col || image[x][y] != oldClr){
            return;
        }

        image[x][y] = newClr;
        dfs(image, x + 1, y, oldClr, newClr); // Down
        dfs(image, x - 1, y, oldClr, newClr); // Up
        dfs(image, x, y + 1, oldClr, newClr); // Right
        dfs(image, x, y - 1, oldClr, newClr); // Left
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldClr = image[sr][sc];
        if(oldClr!=color){
            dfs(image, sr, sc,oldClr,color);
        }
        return image;
    }
};
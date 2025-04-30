

/*
  733. Flood Fill
  This problem is exactly same as Surrounded Regions.
  Here we need to find out all the cells that are connected to image[sr][sc] which has same initial color.
  Mark them to new input color.
  DFS from input cordinates and mark the cells on the way.

  Reference: https://www.youtube.com/watch?v=C-2_uSRli8o&ab_channel=takeUforward
*/


class Solution {

    void dfs(int sr, int sc, int newColor, int iniColor, int deltarow[], int deltacol[], vector<vector<int>> &res, int m, int n ) {

        res[sr][sc] = newColor;
        for(int i=0; i<4; ++i) {
            int neighrow = sr+deltarow[i];
            int neighcol = sc+deltacol[i];
            if(neighrow>=0 && neighrow<m && neighcol>=0 && neighcol <n &&
               res[neighrow][neighcol] == iniColor && res[neighrow][neighcol] != newColor) 
                    dfs(neighrow, neighcol, newColor, iniColor, deltarow, deltacol, res, m, n);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int iniColor = image[sr][sc];
        vector<vector<int>> res = image;
        int deltarow[4] = {-1, 0, 1, 0};
        int deltacol[4] = {0, 1, 0, -1};
        int m = image.size();
        int n = image[0].size();
        dfs(sr, sc, color, iniColor, deltarow, deltacol, res, m, n);
        return res;
    }
};
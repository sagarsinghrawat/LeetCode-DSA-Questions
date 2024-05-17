class Solution {
public:

    int dfs( vector<vector<int>>&grid, vector<vector<int>>& vis, int i, int j ){

        int direction[][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        vis[i][j] = true;
        int ans = 0;
        for( int k = 0 ; k < 4 ; k++ ){

            int newi = i + direction[k][0];
            int newj = j + direction[k][1];
            if( newi<0 || newj<0 || newi>=grid.size() || newj>=grid[0].size() || vis[newi][newj] || grid[newi][newj] == 0 )
                continue;

            ans = max( ans, dfs( grid, vis, newi, newj));
        }

        vis[i][j] = false;
        return grid[i][j] + ans;
    }

    int getMaximumGold(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            for( int j = 0 ; j < m ; j++ ){
                if( grid[i][j] != 0 ){
                    vector<vector<int>> vis( grid.size(), vector<int>( grid[0].size(), false));
                    ans = max( ans, dfs( grid, vis, i, j));
                }
            }
        }

        return ans;
    }
};
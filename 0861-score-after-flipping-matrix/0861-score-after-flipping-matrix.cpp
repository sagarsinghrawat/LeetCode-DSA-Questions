class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        for( int  i = 0 ; i < n ; i++ ){
            if( grid[i][0] == 1){
                for( int j = 0 ; j < m ; j++ ){
                    if(grid[i][j] == 0 )
                        grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }


        for( int j = 0 ; j < m ; j++ ){
            int count = 0;
            for( int i = 0 ; i < n ; i++ ){
                if( grid[i][j] == 1 )
                    count++;
            }

            if( count < n-count ){
                for( int i = 0 ; i < n ; i++ ){
                    if( grid[i][j] == 0)
                        grid[i][j] = 1;
                    else grid[i][j] = 0;
                }
            }
        }

        int ans = 0;
        for( int i = 0 ; i < n ; i++ ){
            int tmp = 0;
            int k = 0;
            for( int j = m-1 ; j>=0 ; j-- ){
                if( grid[i][j] == 1 ){
                    tmp += 1<<k;
                }
                k++;
            }

            ans += tmp;
        }

        return ans;
    }
};
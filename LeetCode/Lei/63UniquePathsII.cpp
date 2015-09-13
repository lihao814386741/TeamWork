class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> u = obstacleGrid;
        int m = int(obstacleGrid.size());
        int n = int(obstacleGrid[0].size());
        for(int i=0; i<int(obstacleGrid.size()); i++)
        {
          for(int j=0; j<int(obstacleGrid[0].size()); j++)
          {
            if(obstacleGrid[i][j]==1)
            {
              u[i][j]=0;
            }
            else if(i>0&&j>0)
            {
              u[i][j]=u[i-1][j]+u[i][j-1];
            }
            else if(i>0)
            {
              u[i][j]=u[i-1][j];
            }
            else if(j>0)
            {
              u[i][j]=u[i][j-1];
            }
            else{
              u[i][j]=1;
            }
          }
        }
    return u[m-1][n-1];
    }
};

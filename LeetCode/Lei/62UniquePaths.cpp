class Solution {
public:
    int uniquePaths(int m, int n) {
        int *matrix = new int[m*n];
        for(int i=0; i<m; i++)
        {
          for(int j=0; j<n; j++)
          {
            if(i==0||j==0)
            {
              matrix[i*n+j]=1;
            }
            else
            {
              matrix[i*n+j]=matrix[(i-1)*n+j]+matrix[i*n+(j-1)];
            }
          }
        }
        int u = matrix[m*n-1];
        delete[] matrix;
        return u;
    }
};

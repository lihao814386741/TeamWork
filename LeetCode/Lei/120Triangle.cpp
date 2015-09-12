class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = int(triangle.size());
        if(row==0)
          return 0;
        int sum[row][row];
        for(int i=0; i<row; i++)
          sum[row-1][i]=triangle[row-1][i];
        for(int i=row-2; i>=0; i--)
          for(int j=0; j<=i; j++)
            sum[i][j]=min(sum[i+1][j],sum[i+1][j+1])+triangle[i][j];
    return sum[0][0];
    }
};

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
      vector<vector<int>> matrix(n);
      if(n<=0)
        return matrix;
      for(int i=0; i<n; i++)
      {
        vector<int> v(n);
        matrix[i]=v;
      }
      int row=n, col=n;
      int r,c;
      int count=1;
      for(r=0,c=0; r<int((row+1)/2)&&c<int((col+1)/2); r++,c++)
      {
        //top
        for(int i=c; i<=(col-1)-c; i++)
        {
          matrix[r][i]=count;
          count++;
        }
        //right
        for(int i=r+1; i<=(row-1)-r; i++)
        {
          matrix[i][(col-1)-c]=count;
          count++;
        }
        //bottom
        for(int i=(col-1)-1-c; (row-1)-r>r&&i>=c; i--)
        {
          matrix[(row-1)-r][i]=count;
          count++;
        }
        //left
        for(int i=(row-1)-1-r; i>r&&(col-1)-1-c>=c; i--)
        {
          matrix[i][c]=count;
          count++;
        }
      }
        
    return matrix;
    }
};

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
       vector<int> res;
       int row = int(matrix.size());
       if(row<=0)
         return res;
       int col = int(matrix[0].size());
       if(col<=0)
         return res;
       int r,c;
       for(r=0,c=0;r<int((row+1)/2)&&c<int((col+1)/2);r++,c++)
       {
         //top
         for(int i=c; i<=(col-1)-c; i++)
         {
           res.push_back(matrix[r][i]);
         }
         //right
         for(int i=r+1; i<=(row-1)-r; i++)
         {
           res.push_back(matrix[i][(col-1)-c]);
         }
         //bottom
         for(int i=(col-1)-1-c; (row-1)-r>r&&i>=c; i--)
         {
           res.push_back(matrix[(row-1)-r][i]);
         }
         //left
         for(int i=(row-1)-1-r; i>r&&(col-1)-1-c>=c ;i--)
         {
           res.push_back(matrix[i][c]);
         }
       }
    return res;
    }
};

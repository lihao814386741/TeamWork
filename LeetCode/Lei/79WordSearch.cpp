class Solution {
public:
    bool Exist(vector<vector<char>>& board, string word, int idx, int row, int col, vector<vector<int>>& mark)
    {
        int i = row;
        int j = col;
        if(board[i][j]==word[idx]&&mark[i][j]==0)
        {
            mark[i][j]=1;
            if(idx+1==word.size())
                return true;
            idx++;
            if( ((i+1)<board.size()&&Exist(board,word,idx,i+1,j,mark)) || (i>0&&Exist(board,word,idx,i-1,j,mark)) || (j>0&&Exist(board,word,idx,i,j-1,mark)) || ((j+1)<board[i].size()&&Exist(board,word,idx,i,j+1,mark)) )
            {
                return true;
            }
            mark[i][j]=0;
        }
    return false;
    }
    
    //recursive backtracking algorithm
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size()<=0||word.size()<=0)
            return false;
        int row = int(board.size());
        int col = int(board[0].size());
        vector<vector<int>> mask(row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(board[i][j]==word[0])
                {
                    vector<vector<int>> mark = mask;
                    if(Exist(board,word,0,i,j,mark))
                        return true;
                }
            }
        }
        return false;
    }
};

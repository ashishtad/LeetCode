class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        if( (0 == board.size()) || (0==word.size()) )
            return false;
        for( int i=0; i< board.size(); ++i)
        {
            for( int j=0; j<board[0].size(); ++j)
            {
                if( board[i][j]==word[0] && DFS(board,word,0,i,j))
                    return true;
            }
        }
        return false;
    }
    bool DFS( vector<vector<char>> &board, string word, 
             int count,int i,int j)
    {
        //Word is found
        if( count == word.size())
            return true;
        //Boundary conditions check
        if( i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[count] )
            return false;
        
        //To take care of not using same letter moer than once
        //Keep the current cell[i][j] in a temp and assign it to space.
        //so that when we traverse again the current cell[i][j] it will fail by above condition             if(board[i][j] != word[count]) .e.g ABA
        char temp = board[i][j];
        board[i][j] =' ';
        //Recursively search for left,right, up and down cells
        bool found = /* downFound*/DFS(board,word,count+1,i+1,j) || /* upFound*/DFS(board,word,count+1,i-1,j) || /* leftFound */  DFS(board,word,count+1,i,j-1) ||
            /* rightFound */ DFS(board,word,count+1,i,j+1);
        
        //since we are goint to return after performing all the search for [i][j]cell
        //Assign it to temp
       board[i][j] = temp;
        return found;
    }
};
class Solution {
public:
    vector<vector<bool>> visited;
    int row;
    int col;
    bool dfs(vector<vector<char>>& board, string word , int r, int c , int index){

        if(r < 0 || c  < 0 ||  r >= row || c >= col) return false;
        if(visited[r][c]) return false;
        if(board[r][c] != word[index] ) return false;
        if(index == word.length()-1) return true;
        visited[r][c] = true;
        if(dfs( board , word ,r+1, c, index+1) || 
        dfs(board , word ,r-1, c, index+1) || 
        dfs(board , word ,r, c+1, index+1) ||
        dfs(board , word ,r, c-1, index+1) )
        {
            visited[r][c] = false;
            return true;
        }
        visited[r][c] = false;
        return false;
    }    

    bool exist(vector<vector<char>>& board, string word) {
        row = board.size();
        col = board[0].size();
        visited = vector(row, vector<bool>(col,false));
        for(int r = 0 ; r < row ; r++)
            for(int c = 0 ; c <  col ; c++ ){
                if(board[r][c] == word[0] ){
                    if(dfs(board , word ,r,c,0)) return true;  
                }
            }
        return false;
    }
};
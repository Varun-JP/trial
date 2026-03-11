class Solution {
public:
    bool row[9][10]; //for just confirmationon the location , no need for actual
    bool col[9][10]; //index saving with this
    bool box[9][10];
    bool solve(vector<vector<char>> &board ){
        for(int r = 0; r< 9 ; r++){
            for(int c =0 ; c < 9 ; c++){
                if(board[r][c] == '.'){
                    int b = (r/3)*3 + (c/3); //index = row * width + col
                    for(int d =1 ; d<= 9 ;d++){
                        if(row[r][d] || col[c][d] || box[b][d])   continue;
                        board[r][c] = '0' + d ; 
                        // row[r][d] → true if digit d is used in row r.
                        row[r][d] = 1, col[c][d] = 1 , box[b][d] =1;
                        if(solve(board)) return true; //since sudoku only has 1 path
                        row[r][d] = 0, col[c][d] = 0 , box[b][d] =0;
                        board[r][c] = '.' ;            
                    }
                    return false; //all digits failed for the curr return , backtrack
                }
            }
        }
        return true; //no empty cell left , board is filled
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int r = 0; r < 9; r++){
            for(int c = 0; c < 9; c++){
                if(board[r][c] != '.'){
                    int d = board[r][c] - '0';
                    int b = (r/3)*3 + (c/3);
                    row[r][d] = col[c][d] = box[b][d] = 1;
                 }
            }
        }
        solve(board);
    }
};